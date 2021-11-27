#include <stdio.h>
typedef struct LL1
{
	/* data */
	int data[100];
	int top = 0; //栈中元素个数
};
void push(LL1 *t, int data)
{
	t->data[t->top] = data;
	t->top++;
};
int get(LL1 *t)
{
	t->top--;
	return t->data[t->top];
};
void prt(LL1 t)
{
	printf("\n--------------------\n");
	printf("出栈顺序：");
	for (int i = t.top; i > 0; i--)
	{
		printf(" %d ", t.data[i - 1]);
	};
	printf("\n--------------------\n");
};
int main(int argc, char const *argv[])
{
	LL1 t1;
	int i=0;
	printf("输入（-1结束）\n");
	scanf("%d",&i);
	while (i!=-1)
	{
		push(&t1,i);
		scanf("%d",&i);
	};
	prt(t1);
	printf("  %d\n",get(&t1));
	printf("  %d\n",get(&t1));
	printf("  %d\n",get(&t1));
	
	return 0;
}
