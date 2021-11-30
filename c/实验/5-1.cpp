#include <stdio.h>
#include <malloc.h>
typedef struct TT //二叉链表单元
{
	char data;
	TT *left = NULL;
	TT *right = NULL;
} * T;
typedef struct S //队列单元
{
	T data;
	S *next = NULL;
};
typedef struct LL //队列
{
	S *tail = (S *)malloc(sizeof(S));
	int ele = 0;
} * L;
void push(LL *t, T data) //入队列
{
	if (t->ele == 0)
	{
		t->tail->data = data;
		t->tail->next = t->tail;
		t->ele++;
	}
	else
	{
		S *d = (S *)malloc(sizeof(S));
		d->data = data;
		d->next = t->tail->next;
		t->tail->next = d;
		t->tail = d;
		t->ele++;
	}
}
T get(L t) //出队列
{
	if (t->ele == 0)
	{
		printf("\n队列为空\n");
		return NULL;
	}
	T data;
	S *d = (S *)malloc(sizeof(S));
	d = t->tail->next;
	t->tail->next = t->tail->next->next;
	t->ele--;
	data = d->data;
	return data;
}
typedef struct ZZ
{
	T data;
	ZZ *next;
};
void zhanpush(ZZ *t, T data) //入栈
{
	ZZ *p = (ZZ *)malloc(sizeof(ZZ));
	p->data = data;
	p->next = t->next;
	t->next = p;
};
T zhanget(ZZ *t) //出栈
{
	if (t->data == 0)
	{
		printf("栈中无内容。\n");
		return 0;
	}
	ZZ *p = (ZZ *)malloc(sizeof(ZZ));
	p = t->next;
	t->next = t->next->next;
	T data = p->data;
	free(p);
	return data;
};
void setin(TT **t) //输入-先根序
{
	char data;
	scanf("%c", &data);
	if (data != ' ')
	{
		TT *p = (TT *)malloc(sizeof(TT));
		*t = p;
		(*t)->data = data;
		setin(&((*t)->left));
		setin(&((*t)->right));
	};
}
void prt1(T t) //打印 -先根序
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		prt1(t->left);
		prt1(t->right);
	}
};
void prt2(T t) //打印 -中根序
{
	if (t != NULL)
	{
		prt2(t->left);
		printf("%c ", t->data);
		prt2(t->right);
	}
};
void prt3(T t) //打印 -后根序
{
	if (t != NULL)
	{
		prt3(t->left);
		prt3(t->right);
		printf("%c ", t->data);
	}
};
void prt4(T t) //打印-先根序-非递归
{
	ZZ z;
	T d = t;
	int ele = 0;
	while (ele || d)
	{
		while (d)
		{
			printf("%c ", d->data);
			zhanpush(&z, d);
			ele++;
			d = d->left;
		}
		d = zhanget(&z);
		ele--;
		d = d->right;
	}
};
void prt5(T t) //打印-中根序-非递归
{
	ZZ z;
	T d = t;
	int ele = 0;
	while (ele || d)
	{
		while (d)
		{
			zhanpush(&z, d);
			ele++;
			d = d->left;
		}
		d = zhanget(&z);
		ele--;
		printf("%c ", d->data);
		d = d->right;
	}
};
void prt6(T t) //打印-后根序-非递归
	{};
void prt7(T t) //打印-层次遍历
{
	LL z;
	push(&z, t); //根
	while (z.ele)
	{
		T d = get(&z);
		printf("%c ", d->data);
		if (d->left)
		{
			push(&z, d->left);
		}
		if (d->right)
		{
			push(&z, d->right);
		}
	}
}
int tall(T t)
{
	if (t == NULL)
	{
		return 0;
	}
	int ldep = tall(t->left);
	int rdep = tall(t->right);
	if (ldep > rdep)
	{
		return ldep + 1;
	}
	else
	{
		return rdep + 1;
	}
}
int yenum(T t)
{
	LL z;
	push(&z, t); //根
	int num=0;
	while (z.ele)
	{
		T d = get(&z);
		if (!d->left&&!d->right)
		{
			num++;
		}
		
		if (d->left)
		{
			push(&z, d->left);
		}
		if (d->right)
		{
			push(&z, d->right);
		}
	};
	return num;
}
int main(int argc, char const *argv[])
{
	T tree = (TT *)malloc(sizeof(TT));
	setin(&tree);
	printf("先根序:");
	prt1(tree);
	printf("\n中根序:");
	prt2(tree);
	printf("\n后根序:");
	prt3(tree);
	printf("\n先根序-非递归:");
	prt4(tree);
	printf("\n中根序-非递归:");
	prt5(tree);
	//printf("\n后根序-非递归:");
	//prt6(tree);
	printf("\n层次遍历:");
	prt7(tree);
	printf("\n高度:%d\n", tall(tree));
	printf("\n");
	printf("叶子数:%d\n", yenum(tree));
	printf("\n");

	return 0;
}
