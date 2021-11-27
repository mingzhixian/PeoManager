#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define mi 15  //迷宫格数 
typedef struct LL
{
	int data = 0;
	LL *next;
};
void push(LL *t, int data) //入栈
{
	LL *p = (LL *)malloc(sizeof(LL));
	p->data = data;
	p->next = t->next;
	t->next = p;
	t->data++; //栈中元素
};
int get(LL *t) //出栈
{
	if (t->data == 0)
	{
		printf("栈中无内容。\n");
		return 0;
	}
	LL *p = (LL *)malloc(sizeof(LL));
	p = t->next;
	t->next = t->next->next;
	int data = p->data;
	free(p);
	t->data--;
	return data;
};
void prt(LL *t) //全部出栈
{
	int a = t->data;
	for (int i = 0; i < a ; i++)
	{
		printf("%d ", get(t));
	};
	printf("\n");
}
void prt2(LL *t) //全部出栈--进制转换
{
	int a = t->data,b;
	for (int i = 0; i < a ; i++)
	{
		b=get(t);
		if (b>9)
		{
			printf("%c", (87+b));
			continue;
		};
		printf("%d", b);
	};
	printf("\n");
};
void prt3(int a[mi][mi])
{
	for (int i = 0; i < mi; i++)
	{
		for (int x = 0; x < mi; x++)
		{
			printf(" %d ",a[i][x]);
		};
		printf("\n");
	}
	
}
int main(int argc, char const *argv[])
{
	LL t; //头
	t.next = 0;

	/*
	int i = 0;
	printf("输入（-1结束）\n");
	scanf("%d", &i);
	while (i != -1)
	{
		push(&t, i);
		scanf("%d", &i);
	};
	printf("  %d\n", get(&t));  //检测
	printf("  %d\n", get(&t));
	printf("  %d\n", get(&t));
	*/

	/*   
	int a, b, d, x, y;  //进制转换
	printf("输入10进制数：");
	scanf("%d", &a);
	printf("输入要转换的进制（2、4、8、16、32）：");
	scanf("%d", &d);
	x = a / d;
	while (x != 0)
	{
		y = a % d;
		push(&t, y);
		a = x;
		x = a / d;
	};
	y = a % d;
	if (y != 0)
	{
		push(&t, y);
	}
	printf("\n-----------------\n转换结果：");
	prt2(&t);
	printf("\n-----------------\n");
	*/

	/*
	char a[100];   //括号匹配 
	printf("输入公式：");
	scanf("%s",a);
	push(&t,1125);
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i]=='(')
		{
			push(&t,1);
		}
		else if (a[i]==')')
		{
			get(&t);
		};
	};
	if (get(&t)==1125)
	{
		printf("匹配。\n");
	}
	else
	{
		printf("不匹配。\n");
	}
	*/

	int a[mi][mi];
	for (int i = 0; i < mi; i++)
	{
		a[0][i]=-1;
		a[mi-1][i]=-1;
		a[i][0]=-1;
		a[i][mi-1]=-1;
	}
	
	
	
	return 0;
}