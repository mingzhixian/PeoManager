#include <stdio.h>
#include <malloc.h>
typedef struct L
{
	int data=0;
	L *next=NULL;
};
typedef struct TT
{
	L *tail=(L *)malloc(sizeof(L));
	int ele=0;
};
void push(TT *t,int data)  //入队列
{
	if (t->ele==0)
	{
		t->tail->data=data;
		t->tail->next=t->tail;
		t->ele++;
	}
	else
	{
		L *d=(L *)malloc(sizeof(L));
		d->data=data;
		d->next=t->tail->next;
		t->tail->next=d;
		t->tail=d;
		t->ele++;
	}
}
int get(TT *t)    //出队列
{
	if (t->ele==0)
	{
		printf("\n队列为空\n");
		return 0;
	}
	int data;
	L *d=(L *)malloc(sizeof(L));
	d=t->tail->next;
	t->tail->next=t->tail->next->next;
	t->ele--;
	data=d->data;
	return data;
}
int main(int argc, char const *argv[])
{
	TT dui;
	push(&dui,2);
	push(&dui,3);
	push(&dui,4);
	push(&dui,5);
	printf("%d  ",get(&dui));
	printf("%d  ",get(&dui));
	printf("%d  ",get(&dui));
	printf("%d  ",get(&dui));
	printf("%d\n",get(&dui));
	printf("%d\n",get(&dui));
	return 0;
}
