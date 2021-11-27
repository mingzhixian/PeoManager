
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
	struct Node* left;  //ָ������
	struct Node* right; //ָ���Һ���
	PointTag Ltag;   //���ұ�־
	PointTag Rtag;
}BitNode,*BitTree;
Status visit(Element e);
Status CreateTree(BitTree &T);
void InThreading(BitTree T);
void InOrderThreading(BitTree &H,BitTree T);
Status InOrderTraverse_Thr(BitTree L);
#endif 
BitTree pre;
Status visit(Element e)  //��ӡԪ��
{
	printf("%c ",e);
	return OK;
}
Status CreateTree(BitTree &T) //ǰ�򴴽�������
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
		if(T->left)          //��ʼ����־,������ΪLink
			T->Ltag = Link;
		CreateTree(T->right);
		if(T->right)
			T->Rtag = Link;
	}
	return OK;
}
void InThreading(BitTree p) //ǰ��������������
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
	H = (BitTree)malloc(sizeof(BitNode));  //����ͷ���
	if(!H)
		exit(OVERFLOW);
	H->right = H; //��ָ���ָ
	H->Rtag = Link;
	if(!T)
	{
		H->left = H;
		H->Ltag = Link; //������Ϊ��,����ָ���ָ
	}
	else
	{
		pre = H;
		H->left = T;
		H->Ltag = Link;
		InThreading(T);		//ǰ�������������������
		pre->right = H;
		pre->Rtag = Thread;
		H->right = pre;
	}
}
Status InOrderTraverse_Thr(BitTree L) //ǰ�����������������
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
	printf("���������������,��ֵ��'#'����,����:('ABDH##I##EJ###CF##G##')\n");
	CreateTree(T);
	InOrderThreading(H,T);
	printf("ǰ��������Ϊ:\n");
	InOrderTraverse_Thr(H);
	return 0;
}
