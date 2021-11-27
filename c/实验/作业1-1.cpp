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
void prt(LL *t) //全部出栈
{
	int a = t->data;
	for (int i = 0; i < a; i++)
	{
		printf("%d ", get(t));
	};
	printf("\n");
}
int bracket()
{
	LL t;
	char a[100]; //括号匹配
	printf("输入：");
	scanf("%s", a);
	push(&t, 1125); //栈底存入特定数字,如果不存入则在最后检测时空栈会打印提示.
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == '(')
		{
			push(&t, 1);
		}
		else if (a[i] == '[')
		{
			push(&t, 2);
		}
		else if (a[i] == '{')
		{
			push(&t, 3);
		}
		else if (a[i] == ')')
		{
			if (get(&t) != 1)
			{
				printf("不符\n");
				return 0;
			}
		}
		else if (a[i] == ']')
		{
			if (get(&t) != 2)
			{
				printf("不符\n");
				return 0;
			}
		}
		else if (a[i] == '}')
		{
			if (get(&t) != 3)
			{
				printf("不符\n");
				return 0;
			}
		}
	};
	if (get(&t) == 1125)
	{
		printf("符合\n");
	}
	else
	{
		printf("不符\n");
	}
}
void canpop()
{
	printf("输入:\n");
	int m, n, k, d[20][20], v, is = 1, ele = 0, top; //m为栈容量,n为入栈元素,k为检查个数,d为检测存储,v为下一个输入值,is判断是否合法,ele存储栈中元素个数,top存储栈顶元素
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) //保存输入
	{
		for (int u = 0; u < n; u++)
		{
			scanf("%d", &d[i][u]);
		}
	};
	for (int i = 0; i < k; i++) //检测
	{
		LL t;
		ele = 0;
		{ //将第一个字母之前的入栈
			for (v = 1; v < d[i][0]; v++)
			{
				if (ele == m - 1) //防止溢出
				{
					is = 0;
					break;
				}
				push(&t, v);
				ele++;
			}
			v = d[i][0] + 1; //v指向下一个要输入的值
			if (is == 0)	 //检测溢出
			{
				printf("NO\n");
				is = 1;
				continue;
			}
		}

		for (int u = 1; u < n; u++) //检查后面数字
		{
			if (ele == 0)
			{
				if (d[i][u] == v)
				{
					v++;
					continue;
				}
				else if (d[i][u] > v)
				{
					for (v; v < d[i][u]; v++)
					{
						if (ele == m - 1) //检测超出
						{
							is = 0;
							break;
						}
						push(&t, v);
						ele++;
					};
					if (is == 0)
					{
						break;
					}
					v = d[i][u] + 1;
				}
				else if (d[i][u] < v)
				{
					is=0;
					break;
				}
			}
			else
			{
				top = get(&t);
				ele--;
				if (d[i][u] < top)
				{
					is = 0;
					break;
				}
				else if (d[i][u] > top)
				{
					push(&t, top);
					ele++;
					for (v; v < d[i][u]; v++)
					{
						if (ele == m - 1) //检测超出
						{
							is = 0;
							break;
						}
						push(&t, v);
						ele++;
					}
					if (is == 0)
					{
						break;
					}
					v = d[i][u] + 1;
				}
				else if (d[i][u] == top)
				{
					continue;
				}
			}
		};
		if (is ==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
			is=1;
		}
	};
}
int main(int argc, char const *argv[])
{
	//bracket(); //括号匹配
	canpop();
	return 0;
}
