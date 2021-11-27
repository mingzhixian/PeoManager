#include <stdio.h>
#include <malloc.h>
typedef struct L  //单个元素
{
	int data=0;
	L *next=NULL;
};
typedef struct TT   //循环链表
{
	L *tail=(L *)malloc(sizeof(L));   //尾
	int ele=0;   //链表中元素个数
};
void push(TT *t,int data)  //入链表
{
	if (t->ele==0)
	{
		t->tail->data=data;
		t->tail->next=t->tail;
		t->ele++;
	}
	else
	{
		L *d=(L *)malloc(sizeof(L));
		d->data=data;
		d->next=t->tail->next;
		t->tail->next=d;
		t->tail=d;
		t->ele++;
	}
}
void luck()   //谁是幸运儿
{
	int m,n;
	printf("输入班级总人数和预设数，空格隔开：");
	scanf("%d %d",&m,&n);
	TT t;   //循环链表
	for (int i = 1; i <= m; i++)   //按顺序排好队
	{
		/* code */
		push(&t,i);
	}
	L *d=(L *)malloc(sizeof(L)),*p=(L *)malloc(sizeof(L));
	d=t.tail;  //当前为循环链表尾部
	while (t.ele!=1)
	{
		/* code */
		//从此处开始仅当循环链表看待，不追究尾部是谁
		for (int i = 1; i < n; i++)
		{
			/* code */
			d=d->next;
		}
		p=d->next;  //p为待删除元素
		printf("s:%d ",p->data);
		d->next=d->next->next;
		t.ele--;
		free(p);
	}
	printf("结果：学号为%d的同学。\n",d->data);
}
int main(int argc, char const *argv[])
{
	luck();  //谁是幸运儿
	return 0;
}
