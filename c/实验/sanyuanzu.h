#include <stdio.h>
typedef struct one
{
	int h, l; //行列坐标
	int data; //值
};
typedef struct SYZ
{
	one data[101];				//三元组，最大非零元素100个
	int frist[20];				//每行第一个数据单元在三元组位置，最大行列数20
	int jh = 0, jl = 0, jd = 0; //矩阵行数jx,最大列数jl,三元组所存个数jd
};
SYZ syzinit(int a[], int h, int l)
{
	SYZ c;
	c.jh = h;
	c.jl = l;
	for (int x = 0; x < h; x++)
	{
		c.frist[x] = c.jd;
		for (int i = 0; i < l; i++)
		{
			if (a[x * h + i] != 0)
			{
				c.data[c.jd].data = a[x * h + i];
				c.data[c.jd].h = x;
				c.data[c.jd].l = i;
				c.jd++;
			}
		}
	}
	return c;
}
SYZ syzadd(SYZ a, SYZ b)
{
	SYZ c;
	c.jh = a.jh;
	c.jl = a.jl;
	for (int i = 0; i < c.jh; i++)
	{
		one af = a.data[a.frist[i]]; //af,bf为该行第一个元素
		one bf = b.data[b.frist[i]];
		int ap = 1, bp = 1;
		c.frist[i] = c.jd;
		while (af.h == i && bf.h == i)
		{
			if (af.l == bf.l)
			{
				c.jd++;
				c.data[c.jd].h = i;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data + bf.data;
				af = a.data[a.frist[i] + ap];
				bf = b.data[b.frist[i] + bp];
				ap++;
				bp++;
			}
			else if (af.l < bf.l)
			{
				c.jd++;
				c.data[c.jd].h = i;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data;
				af = a.data[a.frist[i] + ap];
				ap++;
			}
			else if (af.l > bf.l)
			{
				c.jd++;
				c.data[c.jd].h = i;
				c.data[c.jd].l = bf.l;
				c.data[c.jd].data = bf.data;
				bf = b.data[b.frist[i] + bp];
				bp++;
			}
		}
		while (af.h == i)
		{
			c.jd++;
			c.data[c.jd].h = i;
			c.data[c.jd].l = af.l;
			c.data[c.jd].data = af.data;
			af = a.data[a.frist[i] + ap];
			ap++;
		}
		while (bf.h == i)
		{
			c.jd++;
			c.data[c.jd].h = i;
			c.data[c.jd].l = bf.l;
			c.data[c.jd].data = bf.data;
			bf = b.data[b.frist[i] + bp];
			bp++;
		}
	}
	return c;
}
void syzprt(SYZ a)
{
	for (int i = 0; i < a.jd; i++)
	{
		printf("第%d行第%d列，数值为%d\n",a.data[i].);
	}
	
}