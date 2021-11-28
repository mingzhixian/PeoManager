#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct STR
{
	char *data = NULL;
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
void prt(STR a)
{
	for (int i = 0; i < a.ele; i++)
	{
		printf("%d ",a.data[i]);
	}
}
int main(int argc, char const *argv[])
{
	STR a;
	char b[10];
	scanf("%s",b);
	init(&a,b);
	prt();
	return 0;
}
