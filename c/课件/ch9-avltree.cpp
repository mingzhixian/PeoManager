#include<stdio.h>
#include<stdlib.h>
#define LH 1
#define EH 0
#define RH -1
typedef struct Node
{
	int data;
	int BF;//ƽ�����ӣ�balance factor��
	struct Node *lchild,*rchild;
}BSTNode,*BSTree;
void R_Rotate(BSTree *p)//��pΪ���ڵ�Ķ�����������������ת
{
	BSTree L;
	L=(*p)->lchild;
	(*p)->lchild=L->rchild;
	L->rchild=(*p);
	*p=L;//pָ���µĸ��ڵ�
}
void L_Rotate(BSTree *p)//��pΪ���ڵ�Ķ�����������������ת
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
	 //���T��������ƽ��ȣ�������Ӧ��ƽ�⴦��
		case LH://�½ڵ������T�����ӵ��������ϣ�������������
		(*T)->BF=L->BF=EH;
		R_Rotate(T);
		break;
		case RH://�²���ڵ���T�����ӵ��������ϣ���˫������
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
		case RH://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ������������
		(*T)->BF=R->BF=EH;
 		L_Rotate(T);
		break;
		case LH://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ��˫������
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
bool InsertAVL(BSTree *T,int e,bool *taller)//����taller��ӦT�������
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
		if(e==(*T)->data)//������
		{
			*taller=false;
			return false;
		}
		if(e<(*T)->data)
		{
			if(!InsertAVL(&(*T)->lchild,e,taller))//δ����
			return false;
			if(*taller)//�Բ����������������������
			{
				switch((*T)->BF)
				{
 				    case LH://ԭ�����������������ߣ���Ҫ����ƽ�⴦��
  				    LeftBalance(T);
  				    *taller=false;
  				    break;
  				    case EH://ԭ�����������ȸߣ��������������߶�������
  				    (*T)->BF=LH;
  				    *taller=true;
  				    break;
  				    case RH://ԭ�����������������ߣ��������������ȸ�
 				    (*T)->BF=EH;
  				    *taller=false;
 				     break;
 				 }
			}
		}
        else
		{
		//Ӧ��T������������Ѱ
			if(!InsertAVL(&(*T)->rchild,e,taller))
			 return false;
			if(*taller)//������������������������
			{
				switch((*T)->BF)
				{
				    case LH://ԭ�����������������ߣ��������������ȸ�
					(*T)->BF=EH;
 					*taller=false;
					break;
	 				case EH://ԭ�����������ȸߣ��������������
                    (*T)->BF=RH;
 					*taller=true;
 					break;
 					case RH://ԭ�����������������ߣ�����������ƽ�⴦��
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
    
	printf("��������");
    scanf("%d",&j);
    InsertAVL(&T,j,&taller);
    preorder(T);
    printf("\n");
    Inorder(T);
    printf("\n");
    
	printf("�������������ҳɹ���ƽ�����ҳ���Ϊ��%3.1f",CalAveLength(T,A,num));
    return 0;

}
