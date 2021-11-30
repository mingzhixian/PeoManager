#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct STR
{
	char *data = (char *)malloc(sizeof(char)*0);
	int ele = 0;
};
int init(STR *a, char data[])
{
	int ele = strlen(data);
	a->data = (char *)malloc(sizeof(char) * ele);
	a->ele = ele;
	for (int i = 0; i < ele; i++)
	{
		a->data[i] = data[i];
	}
}
void insert(STR *a, char data)
{
	a->data = (char *)realloc(a->data,sizeof(char) * (a->ele + 1));
	a->data[a->ele] = data;
	a->ele++;
}
int where(STR a, char data) //返回data在a中第几个，有多个只返回第一个出现位置,没有返回-1
{
	for (int i = 0; i < a.ele; i++)
	{
		if (a.data[i] == data)
		{
			return i + 1;
		}
	}
	return -1;
}
STR ianb(STR a, STR b)
{
	//in a not in b
	STR c;
	for (int i = 0; i < a.ele; i++)
	{
		if (where(b, a.data[i]) == -1)
		{
			insert(&c,a.data[i]);
		}
	};
	return c;
}
void prt(STR a)
{
	for (int i = 0; i < a.ele; i++)
	{
		printf("%c ", a.data[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	STR a, b;
	char z[10] = {};
	scanf("%s", z);
	init(&a, z);
	scanf("%s", z);
	init(&b, z);
	STR c = ianb(a, b);
	prt(c);
	return 0;
}
