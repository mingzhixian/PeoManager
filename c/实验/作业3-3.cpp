#include <stdio.h>
#define ele 5
typedef struct DATA
{
	int chinese = 0;
	int math = 0;
	int english = 0;
	int all = 0;
} * TDATA;

void Chg(DATA *a, DATA *b) //交换ab
{
	DATA tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int che(DATA *a, int left, int right)
{
	int x, y;
	x = left + 1;
	y = right - 1;
	while (x < y)
	{
		while (a[left].all >= a[x].all)
		{
			x++;
		}

		while (a[left].all <= a[y].all)
		{
			y--;
		}

		if (x < y)
		{
			Chg(&a[x], &a[y]);
		}
	}
	if (y < x) //此处有相等情况
	{
		Chg(&a[left], &a[y]);
	}
	return y;
}

int Qsort(DATA *a, int left, int right)
{
	if (left < right)
	{
		int y = che(a, left, right);
		Qsort(a, left, y);		//排左边
		Qsort(a, y + 1, right); //排右边
	}
}

DATA input()
{
	DATA a;
	printf("语文成绩：");
	scanf("%d", &a.chinese);
	printf("数学成绩：");
	scanf("%d", &a.math);
	printf("英语成绩：");
	scanf("%d", &a.english);
	a.all = a.chinese + a.english + a.math;
	return a;
}

DATA textinput()
{
	DATA a;
	scanf("%d", &a.chinese);
	scanf("%d", &a.math);
	scanf("%d", &a.english);
	a.all = a.chinese + a.english + a.math;
	return a;
}

void prt(DATA a[])
{
	for (int i = 0; i < ele; i++)
	{
		printf("语文成绩：%d\n", a[i].chinese);
		printf("数学成绩：%d\n", a[i].math);
		printf("英语成绩：%d\n", a[i].english);
		printf("总成绩：%d\n", a[i].all);
	}
}

int main(int argc, char const *argv[])
{
	DATA a[ele];
	for (int i = 0; i < ele; i++)
	{
		a[i] = textinput();
	}
	Qsort(a,0,ele);
	printf("排序后: \n");
	prt(a);
	return 0;
}
