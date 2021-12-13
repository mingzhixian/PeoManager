#include <stdio.h>
#include "sanyuanzu.h"
#include <random>
#include <time.h>
SYZ randata(int x, int y, int k)
{
	srand(time(NULL));
	int n = x * y;
	int d[n], data[n] = {0};
	for (int i = 0; i < n; i++)
		d[i] = i;
	for (int i = n; i > 0; i--)
	{ /* 打乱*/
		int a = i - 1;
		int b = rand() % i;
		if (a != b)
		{
			int t = d[a];
			d[a] = d[b];
			d[b] = t;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			data[i * y + j] = (d[i * y + j] >= (n - k)) ? 1 : 0;
		}
	}
	SYZ c = syzinit(data, x, y);
	return c;
}
int main(int argc, char const *argv[])
{
	printf("输入 m、p、n、k1、k2：(空格隔开)\n");
	int m, p, n, k1, k2;
	scanf("%d %d %d %d %d", &m, &p, &n, &k1, &k2);
	SYZ a = randata(m, p, k1);
	SYZ b = randata(p, n, k2);
	SYZ c = syzadd(a, b);
	SYZ d = syzsub(a, b);
	SYZ e = syzmul(a, b);
	syzprt(a);
	printf("\n");
	syzprt(b);
	printf("\n");
	syzprt(c);
	printf("\n");
	syzprt(d);
	printf("\n");
	syzprt(e);

	return 0;
}
