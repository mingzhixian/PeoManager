#include<stdio.h>
#include<stdlib.h>
#define LH 1
#define EH 0
#define RH -1
typedef struct Node
{
	int data;
	int BF;//平衡因子（balance factor）
	struct Node *lchild,*rchild;
}BSTNode,*BSTree;
void R_Rotate(BSTree *p)//以p为根节点的二叉排序树进行右旋转
{
	BSTree L;
	L=(*p)->lchild;
	(*p)->lchild=L->rchild;
	L->rchild=(*p);
	*p=L;//p指向新的根节点
}
void L_Rotate(BSTree *p)//以p为根节点的二叉排序树进行左旋转
{
	BSTree R;
	R=(*p)->rchild;
	(*p)->rchild=R->lchild;
	R->lchild=(*p);
	*p=R;
}
void LeftBalance(BSTree *T)
{
	BSTree L,Lr;
	L=(*T)->lchild;
	switch(L->BF)
	{
	 //检查T的左子树平衡度，并作相应的平衡处理
		case LH://新节点插入在T的左孩子的左子树上，做单右旋处理
		(*T)->BF=L->BF=EH;
		R_Rotate(T);
		break;
		case RH://新插入节点在T的左孩子的右子树上，做双旋处理
		Lr=L->rchild;
		switch(Lr->BF)
 		{
			 case LH:
		     (*T)->BF=RH;
 			 L->BF=EH;
             break;
             case EH:
             (*T)->BF=L->BF=EH;
             break;
             case RH:
             (*T)->BF=EH;
             L->BF=LH;
             break;
		}
        Lr->BF=EH;
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
	}
}
void RightBalance(BSTree *T)
{
	BSTree R,Rl;
	R=(*T)->rchild;
	switch(R->BF)
	{
		case RH://新节点插在T的右孩子的右子树上，要做单左旋处理
		(*T)->BF=R->BF=EH;
 		L_Rotate(T);
		break;
		case LH://新节点插在T的右孩子的左子树上，要做双旋处理
		Rl=R->lchild;
		switch(Rl->BF)
		{
 			case LH:
 			(*T)->BF=EH;
 			R->BF=RH;
 			break;
 			case EH:
 			(*T)->BF=R->BF=EH;
		    break;
 			case RH:
 			(*T)->BF=LH;
 			R->BF=EH;
 			break;
		}
		Rl->BF=EH;
    	R_Rotate(&(*T)->rchild);
    	L_Rotate(T);
	}
}
bool InsertAVL(BSTree *T,int e,bool *taller)//变量taller反应T长高与否
{
	if(!*T)
	{
		*T=(BSTree)malloc(sizeof(BSTNode));
		(*T)->data=e;
		(*T)->lchild=(*T)->rchild=NULL;
		(*T)->BF=EH;
		*taller=true;
	}
	else
	{
		if(e==(*T)->data)//不插入
		{
			*taller=false;
			return false;
		}
		if(e<(*T)->data)
		{
			if(!InsertAVL(&(*T)->lchild,e,taller))//未插入
			return false;
			if(*taller)//以插入左子树，且左子树变高
			{
				switch((*T)->BF)
				{
 				    case LH://原本左子树比右子树高，需要做左平衡处理
  				    LeftBalance(T);
  				    *taller=false;
  				    break;
  				    case EH://原本左右子树等高，现因左子树增高而树增高
  				    (*T)->BF=LH;
  				    *taller=true;
  				    break;
  				    case RH://原本右子树比左子树高，现在左右子树等高
 				    (*T)->BF=EH;
  				    *taller=false;
 				     break;
 				 }
			}
		}
        else
		{
		//应在T的右子树中搜寻
			if(!InsertAVL(&(*T)->rchild,e,taller))
			 return false;
			if(*taller)//插入右子树，且右子树长高
			{
				switch((*T)->BF)
				{
				    case LH://原本左子树比右子树高，现在左右子树等高
					(*T)->BF=EH;
 					*taller=false;
					break;
	 				case EH://原本左右子树等高，现在右子树变高
                    (*T)->BF=RH;
 					*taller=true;
 					break;
 					case RH://原本右子树比左子树高，现在需做右平衡处理
				    RightBalance(T);
 					*taller=false;
				    break;
				}
			}
		}
	}
    return true;
}
bool Find(BSTree T,int key)
{
	if(!T)
		return false;
    else if(T->data==key)
		return true;
	else if(T->data<key)
		return Find(T->rchild,key);
	else
		return Find(T->lchild,key);
}
void preorder(BSTree T)
{
	if(T)
	{
		printf("%d  ",T->data);
		if(T->lchild||T->rchild)
		{
			printf("(");
			preorder(T->lchild);
			printf(",");
			preorder(T->rchild);
			printf(")");
		}
	}
}
void Inorder(BSTree T)
{
	if(T)
	{ Inorder(T->lchild);
	  printf("%d   ",T->data);
	  Inorder(T->rchild);
	}
}
double CalAveLength(BSTree T,int A[],int num)
{
	double len=0;
	int i;
	BSTree rt;
	for(i=0;i<num;i++)
	{
		rt=T;
		for(;;)
		{
			len++;
			if (rt->data==A[i])	
				break;
			if(rt->data<A[i])
				rt=rt->rchild;
			else
				rt=rt->lchild;
		}
	}
    return (double)len/num;
}
int main()
{
    int i;
    int j;
    int num;
    int A[]={3,2,1,4,11,6,7,10,9,8};
    BSTree T=NULL;
    bool taller;
    num=sizeof(A)/sizeof(int);
    for(i=0;i<sizeof(A)/sizeof(int);i++)
    InsertAVL(&T,A[i],&taller);
    preorder(T);
    printf("\n");
    Inorder(T);
    printf("\n");
    
	printf("插入数：");
    scanf("%d",&j);
    InsertAVL(&T,j,&taller);
    preorder(T);
    printf("\n");
    Inorder(T);
    printf("\n");
    
	printf("二叉排序树查找成功的平均查找长度为：%3.1f",CalAveLength(T,A,num));
    return 0;

}
