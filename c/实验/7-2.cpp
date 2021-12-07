#include <stdio.h>
#include <malloc.h>
typedef struct Tree //二叉链表单元
{
	int data=0;
	Tree *left = NULL;
	Tree *right = NULL;
} * TTree;
void InsertTree(TTree a,int data)
{
	TTree p=a;
	while (p!=NULL)
	{
		if (p->data<data)
		{
			p=p->left;
		}
		else if (p->data>data)
		{
			p=p->right;
		}
		else
		{
			printf("重复了。\n");
		}
	}
	p=(Tree *)malloc(sizeof(Tree));
	p->data=data;
}
int SearchTree(TTree a)
{

}
void DelTree(TTree a,int data)
{

}
void PrtTree(TTree t) //打印 -先根序
{
	if (t != NULL)
	{
		printf("%d", t->data);
		PrtTree(t->left);
		PrtTree(t->right);
	}
	else
	{
		printf("0");
	}
};
int main(int argc, char const *argv[])
{
	TTree a;
	int data;
	for (int i = 0; i < 4; i++)
	{
		printf("输入：");
		scanf("%d",&data);
		InsertTree(a,data);
	}
	printf("%d",a->data);
	//PrtTree(a);
	return 0;
}
