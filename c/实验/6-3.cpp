#include <stdio.h>
//深度优先遍历
typedef struct TT
{
	int sp[10];
	int top;
};
int pop(TT *t)
{
	t->top--;
	return t->sp[t->top + 1];
}
int push(TT *t, int i)
{
	t->top++;
	t->sp[t->top] = i;
}
int main(int argc, char const *argv[])
{
	int c[8][8] = {{0, 1, 1, 100, 100, 100, 100, 100},
				   {100, 0, 100, 1, 1, 100, 100, 100},
				   {100, 100, 0, 100, 100, 1, 1, 100},
				   {100, 1, 100, 0, 100, 100, 100, 1},
				   {100, 1, 100, 100, 0, 100, 100, 1},
				   {100, 100, 1, 100, 100, 0, 1, 100},
				   {100, 100, 1, 100, 100, 1, 0, 100},
				   {100, 100, 100, 1, 1, 100, 100, 0}};
	int f[8] = {0}, i, e;
	TT stk;
	stk.top = -1;
	push(&stk, 0);
	f[0] = 1;
	while (stk.top >= 0)
	{
		e = pop(&stk);
		printf("%d ->", e+1);
		for (i = 0; i < 8; ++i)
			if (f[i] == 0 && c[e][i] > 0 && c[e][i] < 100)
			{
				push(&stk, i);
				f[i] = 1;
			}
	}
	return 0;
}