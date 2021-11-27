#include <stdio.h>
#include <malloc.h>
#include <string.h>
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
int bracket()  //括号匹配
{
	LL t;
	char a[100];   //括号匹配 
	printf("输入(可检测小、中、大括号,@结束)：");
	scanf("%s",a); //(@也存储了，在需要输出时表达式应为strlen-1)
	push(&t,1125);  //栈底存入特定数字,如果不存入在最后检测时是否空栈时会打印提示,所以存入特定数字防止打印提示.
	for (int i = 0; i < strlen(a)-1; i++)
	{
		//思想：检测到左括号入栈，检测到右括号则检测栈顶是否匹配
		if (a[i]=='(')
		{
			push(&t,1);
		}
		if (a[i]=='[')
		{
			push(&t,2);
		}
		if (a[i]=='{')
		{
			push(&t,3);
		}
		else if (a[i]==')')
		{
			if (get(&t)!=1)
			{
				printf("不符\n");
				return 0;
			}
		}
		else if (a[i]==']')
		{
			if (get(&t)!=2)
			{
				printf("不符\n");
				return 0;
			}
		}
		else if (a[i]=='}')
		{
			if (get(&t)!=3)
			{
				printf("不符\n");
				return 0;
			}
		}
	};
	//检测是否栈为空
	if (get(&t)==1125)
	{
		printf("符合\n");
	}
	else
	{
		printf("不符\n");
	}
}
int main(int argc, char const *argv[])
{
	bracket();   //括号匹配
	return 0;
}


