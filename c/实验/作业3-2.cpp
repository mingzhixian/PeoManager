#include <stdio.h>
#define ele 5
typedef struct DATA
{
	int chinese = 0;
	int math = 0;
	int english = 0;
	int all = 0;
} * TDATA;

void Merge(DATA a[], int left, int mid, int right)
{
	DATA tmp[right - left + 1];
	int p1 = left;
	int p2 = mid + 1;
	int i = 0;
	while (p1 <= mid && p2 <= right)
	{
		tmp[i++] = a[p1].all <= a[p2].all ? a[p1++] : a[p2++];
	}
	while (p1 <= mid)
	{
		tmp[i++] = a[p1++];
	}
	while (p2 <= right)
	{
		tmp[i++] = a[p2++];
	}
	for (i = 0; i < right - left + 1; i++)
	{
		a[left + i] = tmp[i];
	}
}

int Process(DATA a[], int left, int right)
{
	if (left == right) //结束条件
	{
		return 1;
	}
	int mid = left + ((right - left) >> 1);
	Process(a, left, mid);
	Process(a, mid + 1, right);
	Merge(a, left, mid, right);
}

int MergeSort(DATA a[])
{
	Process(a, 0, ele - 1);
	return 1;
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
	MergeSort(a);
	printf("排序后: \n");
	prt(a);
	return 0;
}
