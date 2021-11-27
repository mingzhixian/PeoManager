#include <stdio.h>
#include <malloc.h>
typedef struct List
{
	int data; //链式链表
	List *next;
};
int inp(List *h)   //插入 
{
	int a = 1;
	printf("输入data,按0结束 \n");
	scanf("%d", &a);
	while (a != 0)
	{
		List *r = (List *)malloc(sizeof(List));
		r->data = a;
		r->next = h->next;
		h->next = r;
		h->data = h->data + 1; //链头记录当前链记录数
		printf("输入data,按0结束 \n");
		scanf("%d", &a);
	};
	return 0;
};
int prt(List h) //打印
{
	printf("打印:\n");
	List *p = (List *)malloc(sizeof(List));
	p = &h;
	printf("链表中共用%d个节点：", p->data);
	p = p->next;
	while (p->next != 0)
	{
		printf("%d -> ", p->data);
		p = p->next;
	};
	printf("%d", p->data);
	printf("\n");
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
int del(List *h, int f)   //删除指定值 
{
	List *p = (List *)malloc(sizeof(List));
	p = h;
	while (p->next != 0)
	{
		if (p->next->data == f)
		{
			p->next = p->next->next;
			h->data--;
			printf("完成\n");
			return 1;
		};
		p = p->next;
	};
	printf("执行错误，删除对象未在链表中。");
	return 0;
};
int ins(List *h, int f, int data) //f之后插入 ，插入数据为data
{
	List *r = (List *)malloc(sizeof(List)), *p = (List *)malloc(sizeof(List));
	p = h;
	for (f; f > 0 && p->next != 0; f--) //当f超出范围后，在末尾插入
	{
		p = p->next;
	}
	r->data = data;
	r->next = p->next;
	p->next = r;
	h->data = h->data + 1;
};
int add(List *h1, List *h2, List *h3)   //有序表归并 
{
	List *r = (List *)malloc(sizeof(List)), *p = (List *)malloc(sizeof(List)), *x = (List *)malloc(sizeof(List)), *y = (List *)malloc(sizeof(List));
	p = h1;
	r = h2;
	while (r->next != 0 && p->next != 0)
	{
		if (r->next->data < p->next->data)
		{
			ins(h3, h3->data, r->next->data);
			r = r->next;
		}
		else if (r->next->data > p->next->data)
		{
			ins(h3, h3->data, p->next->data);
			p = p->next;
		}
		else
		{
			ins(h3, h3->data, r->next->data);
			r = r->next;
			p = p->next;
		};
	};
	while (r->next != 0)
	{
		ins(h3, h3->data, r->next->data);
		r = r->next;
	};
	while (p->next != 0)
	{
		ins(h3, h3->data, p->next->data);
		p = p->next;
	};
	return 1;
};
int sor(List *h)    //排序  
{
	List *p = (List *)malloc(sizeof(List)), *r = (List *)malloc(sizeof(List)), *z = (List *)malloc(sizeof(List));
	z = h;
	while (z->next != 0)
	{
		int min = z->next->data;
		p = z;
		while (p->next != 0)
		{
			if (p->next->data <= min)
			{
				min = p->next->data;
				r = p;
			};
			p = p->next;
		};
		p = r->next;
		r->next = r->next->next;
		p->next = z->next;
		z->next = p;
		z = z->next;
	}
	return 1;
};
int plus(List *h1, List *h2, List *h3)   //集合的并 
{
	sor(h1);
	sor(h2);
	add(h1, h2, h3);
};
int dif(List *h1, List *h2, List *h3)  //集合的差 
{
	plus(h1, h2, h3);
	List *p = (List *)malloc(sizeof(List)), *r = (List *)malloc(sizeof(List));
	p = h2;
	while (p->next != 0)
	{
		r = h3;
		while (r->next != 0)
		{
			if (p->next->data==r->next->data)
			{
				del(h3,p->next->data);
				break;
			};
			r=r->next;
		};
		p=p->next;
	}
	return 1;
};
int jiao(List *h1, List *h2, List *h3)   //集合的交集 
{
	List *p = (List *)malloc(sizeof(List)), *r = (List *)malloc(sizeof(List));
	p = h2;r=h1;
	while (p->next != 0)
	{
		if(find(*h1,p->next->data)>0)
		{
			ins(h3,h3->data,p->next->data);
		}
		p=p->next;
	}
	return 1;
};
int main()
{
	List h;
	h.data=0;
	h.next=0;
	printf("初始化链表。 \n");
	inp(&h);
	prt(h);
	printf("链表查找数据为4的节点：\n");
	find(h,4);
	printf("链表删除数据为2的节点：\n");
	del(&h,2);
	prt(h);
	printf("链表在第2个节点之后插入数据为5的节点：\n");
	ins(&h,2,5);
	prt(h);
	printf("两个有序链表的归并：\n");
	List h1;
	h1.data = 0;
	h1.next = 0;
	inp(&h1);
	printf("有序链表1：\n");
	prt(h1);
	List h2;
	h2.data = 0;
	h2.next = 0;
	inp(&h2);
	printf("有序链表2：\n");
	prt(h2);
	List h3;
	h3.data = 0;
	h3.next = 0;
	add(&h1, &h2, &h3);
	printf("归并后的链表：\n");
	prt(h3);
	printf("链表排序：\n");
	List h4;
	h4.data = 0;
	h4.next = 0;
	inp(&h4);
	printf("排序前：\n");
	prt(h4);
	sor(&h4);
	printf("排序后：\n");
	prt(h4);
	printf("集合：\n");
	List h5;
	h5.data = 0;
	h5.next = 0;
	inp(&h5);
	printf("链表：\n");
	prt(h5);
	List h6;
	h6.data = 0;
	h6.next = 0;
	inp(&h6);
	printf("链表：\n");
	prt(h6);
	List h7;
	h7.data = 0;
	h7.next = 0;
	plus(&h5, &h6, &h7);
	printf("并：\n");
	prt(h7);
	List h8;
	h8.data = 0;
	h8.next = 0;
	dif(&h5, &h6, &h8);
	printf("差：\n");
	prt(h8);
	List h9;
	h9.data = 0;
	h9.next = 0;
	jiao(&h5, &h6, &h9);
	printf("交：\n");
	prt(h9);
	return 0;
}