#include <malloc.h>
typedef struct ONEDUI //队列单元
{
	int data = 0;
	ONEDUI *next = NULL;
};
typedef struct DUI
{
	ONEDUI *tail = (ONEDUI *)malloc(sizeof(ONEDUI));
	int ele = 0;
} * ZDUI;
void duipush(ZDUI t, int data) //入队列
{
	if (t->ele == 0)
	{
		t->tail->data = data;
		t->tail->next = t->tail;
		t->ele++;
	}
	else
	{
		ONEDUI *d = (ONEDUI *)malloc(sizeof(ONEDUI));
		d->data = data;
		d->next = t->tail->next;
		t->tail->next = d;
		t->tail = d;
		t->ele++;
	}
}
int duiget(ZDUI t) //出队列
{
	if (t->ele == 0)
	{
		printf("\n队列为空\n");
		return 0;
	}
	int data;
	ONEDUI *d = (ONEDUI *)malloc(sizeof(ONEDUI));
	d = t->tail->next;
	t->tail->next = t->tail->next->next;
	t->ele--;
	data = d->data;
	return data;
}
void duiprt(ZDUI t) //全部出队
{
	while (t->ele)
	{
		printf("%d ", duiget(t));
	}
	printf("\n");
}