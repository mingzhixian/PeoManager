#include <stdio.h>
#define ele 10
void Chg(int *a, int *b) //交换ab
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int che(int *a, int left, int right)
{
	int x, y;
	x = left + 1;
	y = right - 1;
	while (x < y)
	{
		while (a[left] >= a[x])
		{
			x++;
		}

		while (a[left] <= a[y])
		{
			y--;
		}

		if (x < y)
		{
			Chg(&a[x], &a[y]);
		}
	}
	if (y<x)//此处有相等情况
	{
		Chg(&a[left], &a[y]);
	}
	return y;
}
int Qsort(int *a, int left, int right)
{
	if (left < right)
	{
		int y = che(a, left, right);
		Qsort(a, left, y);		//排左边
		Qsort(a, y + 1, right); //排右边
	}
}
void prt(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void input(int *a, int n)
{
	printf("输入数组：\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}
int main(int argc, char const *argv[])
{
	int a[ele];
	input(a, ele);
	printf("排序前：\n");
	prt(a, ele);
	Qsort(a, 0, ele);
	printf("排序后:\n");
	prt(a, ele);
	return 0;
}
