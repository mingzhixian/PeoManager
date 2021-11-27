#include <stdio.h>
#include <malloc.h>
typedef struct List
{
	int data; //链式链表
	List *next;
};
void inp(List *h, int a) //插入
{
	List *r = (List *)malloc(sizeof(List));
	r->data = a;
	r->next = h->next;
	h->next = r;
	h->data = h->data + 1; //链头记录当前链记录数
};
int prt(List *h) //打印
{
	printf("打印:\n");
	List *p = (List *)malloc(sizeof(List));
	p = h;
	printf("链表中共用%d个节点：", p->data);
	while (p->next != 0)
	{
		printf("%d -> ", p->next->data);
		p = p->next;
	};
	printf("end\n");
	return 0;
};
int find(List h, int f) //查找（按值查找，可以改为按位置查找）
{
	List *p = (List *)malloc(sizeof(List));
	p = &h;
	int a = 0;
	while (p->next != 0)
	{
		p = p->next;
		a++; //第a个
		if (p->data == f)
		{
			printf("找到了。\n");
			return a;
		}
	};
	printf("未找到。\n");
	return 0;
};
int del(List *h, int f) //删除指定值
{
	List *p = (List *)malloc(sizeof(List));
	p = h;
	while (p->next != 0)
	{
		if (p->next->data == f)
		{
			p->next = p->next->next;
			h->data--;
			return 1;
		};
		p = p->next;
	};
	printf("执行错误，删除对象未在链表中。");
	return 0;
};
int min(List *h)
{
	List *p = (List *)malloc(sizeof(List));
	p = h;
	int a=p->next->data;
	while (p->next != 0)
	{
		if (a>p->next->data)
		{
			a=p->next->data;
		}
		p = p->next;
	};
	return a;
}
int main(int argc, char const *argv[])
{
	List a;
	a.next=0;
	a.data=0;
	inp(&a,3);
	inp(&a,4);
	inp(&a,5);
	inp(&a,32);
	inp(&a,8);
	inp(&a,6);
	inp(&a,13);
	int z,x;
	while (a.data>1)
	{
		z=min(&a);
		del(&a,z);
		x=min(&a);
		del(&a,x);
		printf("(%d,%d) ",z,x);
		inp(&a,(x+z));
	}
	printf("\n");
	return 0;
}
