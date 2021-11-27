#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW 1
#define ok 1
#define ERROR 0

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct{
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack;

int main()
{
	int InitStack(SqStack &S);
	int Push(SqStack &S,BiTree T);
	BiTree Pop(SqStack &S);
	BiTree GetTop(SqStack &S);
	int StackEmpty(SqStack &s);
	int InOrder(BiTree T);
	int PreOrder(BiTree T);
	int PostOrder(BiTree T);
	int CreateBiTree(BiTree &T);
	
	
	BiTree T;
	printf("请输入树的节点(#代表空):\n");
	CreateBiTree(T);
	 PreOrder(T);
	printf("\n");
   InOrder(T);
   	printf("\n");
	PostOrder(T);
  	printf("\n");
	return 0;
	
}

int CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {T=NULL;}
    else
    {
    	T = (BiTNode*)malloc(sizeof(BiTNode));
    	if(!T)
		{exit(OVERFLOW);}
    	T->data=ch;
    	CreateBiTree(T->lchild);
    	CreateBiTree(T->rchild);
	}
	
	return 0;
}


int InitStack(SqStack &S)
{
	S.base=(BiTree*)malloc(STACK_INIT_SIZE * sizeof(BiTree));
	if(!S.base)
	{
		printf("error");
		exit(OVERFLOW);
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	
	return ok;
}


int Push(SqStack &S,BiTree T)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(BiTree *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));  
		if(!S.base){printf("error");exit(OVERFLOW);}	
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;		
	}
	*S.top++=T;
	
	return ok;
}


BiTree Pop(SqStack &S)
{
	BiTree e;
	if(S.top==S.base){printf("error");return ERROR;}
	e=*--S.top;
	//printf("%c",e);
	return e;
}

int StackEmpty(SqStack &s) 
{     //判断栈空
	if (s.top == s.base){return true;}
	else {return false;}
}

BiTree GetTop(SqStack &S)
{
	if(S.top==S.base)
	{return ERROR;}
	
	return *(S.top-1);
}



//非递归中序遍历 
int InOrder(BiTree T)
{
	int InitStack(SqStack &S);
	int Push(SqStack &S,BiTree T);
	BiTree Pop(SqStack &S);
	int StackEmpty(SqStack &s);
	
	SqStack S1;
	BiTree p1=T;
	InitStack(S1);
	Push(S1,p1);
	while(p1||!StackEmpty(S1))
	{
		while(p1)
		{
			p1=p1->lchild;
			Push(S1,p1);
		}
		Pop(S1);
		if(!StackEmpty(S1))
		{
			p1=Pop(S1);
			printf("%c",p1->data);
			//p=p->rchild;
			Push(S1,p1->rchild);
			p1=p1->rchild;
		}
	}

	return 0;	
}

//非递归先序遍历 
int PreOrder(BiTree T)
{
	int InitStack(SqStack &S);
	int Push(SqStack &S,BiTree T);
	BiTree Pop(SqStack &S);
	int StackEmpty(SqStack &s);

	
	SqStack S2;
	BiTree p2=T;
	InitStack(S2);
	while(!StackEmpty(S2)||p2)
	{
		while(p2)
		{
			printf("%c",p2->data);
			Push(S2,p2);
			p2=p2->lchild;
		}
		if(!StackEmpty(S2))
		{
			p2=Pop(S2);
			p2=p2->rchild;
		}
	}
	
	return 0;	
}


//非递归后序遍历 
int PostOrder(BiTree T)
{
	int InitStack(SqStack &S);
	int Push(SqStack &S,BiTree T);
	BiTree Pop(SqStack &S);
	int StackEmpty(SqStack &s);

	
	SqStack S3;
	BiTree p3=T;
	BiTNode *pre=NULL,*cur=NULL;
	InitStack(S3);
	
	Push(S3,p3);
	while(!StackEmpty(S3))
	{
		cur=GetTop(S3);
		if((cur->lchild==NULL && cur->rchild==NULL) || (pre!=NULL && (pre==cur->lchild || pre==cur->rchild)))
		{
			printf("%c",Pop(S3)->data);	
			pre=cur;
		}
		else
		{
			if(cur->rchild!=NULL)
			{Push(S3,cur->rchild);}
			if(cur->lchild!=NULL)
			{Push(S3,cur->lchild);}
		} 
	}
	return 0;
}






