
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef BITTREE_H
#define BITTREE_H
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef enum{Link,Thread} PointTag;
typedef char Element;
typedef int Status;
typedef struct Node{
	Element data;
	struct Node* left;  //指向左孩子
	struct Node* right; //指向右孩子
	PointTag Ltag;   //左右标志
	PointTag Rtag;
}BitNode,*BitTree;
Status visit(Element e);
Status CreateTree(BitTree &T);
void InThreading(BitTree T);
void InOrderThreading(BitTree &H,BitTree T);
Status InOrderTraverse_Thr(BitTree L);
#endif 
BitTree pre;
Status visit(Element e)  //打印元素
{
	printf("%c ",e);
	return OK;
}
Status CreateTree(BitTree &T) //前序创建二叉树
{
	Element ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;
	else
	{
		T = (BitTree)malloc(sizeof(BitNode));
		if(!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateTree(T->left);
		if(T->left)          //初始化标志,有左孩子为Link
			T->Ltag = Link;
		CreateTree(T->right);
		if(T->right)
			T->Rtag = Link;
	}
	return OK;
}
void InThreading(BitTree p) //前序线索化二叉树
{
	if(p)
	{
		if(!p->left)
		{
			p->left = pre;
			p->Ltag = Thread;
		}
		if(!pre->right)
		{
			pre->right = p;
			pre->Rtag = Thread;
		}
		pre = p;
		if(p->Ltag == Link)
			InThreading(p->left);
		if(p->Rtag == Link)
			InThreading(p->right);
	}
}
void InOrderThreading(BitTree &H,BitTree T)
{
	H = (BitTree)malloc(sizeof(BitNode));  //建立头结点
	if(!H)
		exit(OVERFLOW);
	H->right = H; //右指针回指
	H->Rtag = Link;
	if(!T)
	{
		H->left = H;
		H->Ltag = Link; //二叉树为空,则左指针回指
	}
	else
	{
		pre = H;
		H->left = T;
		H->Ltag = Link;
		InThreading(T);		//前序遍历进行中序线索化
		pre->right = H;
		pre->Rtag = Thread;
		H->right = pre;
	}
}
Status InOrderTraverse_Thr(BitTree L) //前序遍历线索化二叉树
{
	BitTree p = L->left;
	while(p != L)
	{
		visit(p->data);
		if(p->Ltag == Link)
			p = p->left;
		else
			p = p->right;
	}
	return OK;

}
int main()
{
	BitTree H,T;
	printf("请输入二叉树数据,空值以'#'代替,例如:('ABDH##I##EJ###CF##G##')\n");
	CreateTree(T);
	InOrderThreading(H,T);
	printf("前序遍列序号为:\n");
	InOrderTraverse_Thr(H);
	return 0;
}
