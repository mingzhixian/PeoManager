#include <malloc.h>
typedef struct ZHAN
{
	int data = 0;
	ZHAN *next;
} * ZZHAN;
void zhanpush(ZZHAN t, int data) //入栈
{
	ZZHAN p = (ZHAN *)malloc(sizeof(ZHAN));
	p->data = data;
	p->next = t->next;
	t->next = p;
	t->data++; //栈中元素
};
int zhanget(ZZHAN t) //出栈
{
	if (t->data == 0)
	{
		printf("栈中无内容。\n");
		return 0;
	}
	ZZHAN p = (ZHAN *)malloc(sizeof(ZHAN));
	p = t->next;
	t->next = t->next->next;
	int data = p->data;
	free(p);
	t->data--;
	return data;
};
void zhanprt(ZZHAN t) //全部出栈
{
	while (t->data)
	{
		printf("%d ", zhanget(t));
	};
	printf("\n");
}