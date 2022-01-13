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
			if (a[x * l + i] != 0)
			{
				c.data[c.jd].data = a[x * l + i];
				c.data[c.jd].h = x + 1;
				c.data[c.jd].l = i + 1;
				c.jd++;
			}
		}
	}
	return c;
}
void syztodata(SYZ a, int (*data)[])
{
	int h = a.jh;
	int l = a.jl;
	for (int x = 0; x < h * l; x++)
	{
		(*data)[x] = 0;
	}
	for (int i = 0; i < a.jd; i++)
	{
		(*data)[(a.data[i].h-1) * l + a.data[i].l-1] = a.data[i].data;
	}
}
SYZ syzadd(SYZ a, SYZ b)
{
	SYZ c;
	c.jh = a.jh;
	c.jl = a.jl;
	if (a.jh != b.jh || a.jl != b.jl)
	{
		printf("行列数不相等不能相加。\n");
		return c;
	}
	for (int i = 0; i < c.jh; i++) //第i行
	{
		one af = a.data[a.frist[i]]; //af,bf为该行第一个元素
		one bf = b.data[b.frist[i]];
		int ap = 1, bp = 1; //下一个
		c.frist[i] = c.jd;
		while (af.h == i + 1 && bf.h == i + 1)
		{
			if (af.l == bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data + bf.data;
				c.jd++;
				af = a.data[a.frist[i] + ap];
				bf = b.data[b.frist[i] + bp];
				ap++;
				bp++;
			}
			else if (af.l < bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data;
				c.jd++;
				af = a.data[a.frist[i] + ap];
				ap++;
			}
			else if (af.l > bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = bf.l;
				c.data[c.jd].data = bf.data;
				c.jd++;
				bf = b.data[b.frist[i] + bp];
				bp++;
			}
		}
		while (af.h == i + 1)
		{
			c.data[c.jd].h = i + 1;
			c.data[c.jd].l = af.l;
			c.data[c.jd].data = af.data;
			c.jd++;
			af = a.data[a.frist[i] + ap];
			ap++;
		}
		while (bf.h == i + 1)
		{
			c.data[c.jd].h = i + 1;
			c.data[c.jd].l = bf.l;
			c.data[c.jd].data = bf.data;
			c.jd++;
			bf = b.data[b.frist[i] + bp];
			bp++;
		}
	}
	return c;
}
SYZ syzsub(SYZ a, SYZ b)
{
	SYZ c;
	c.jh = a.jh;
	c.jl = a.jl;
	if (a.jh != b.jh || a.jl != b.jl)
	{
		printf("行列数不相等不能相减。\n");
		return c;
	}
	for (int i = 0; i < c.jh; i++) //第i行
	{
		one af = a.data[a.frist[i]]; //af,bf为该行第一个元素
		one bf = b.data[b.frist[i]];
		int ap = 1, bp = 1; //下一个
		c.frist[i] = c.jd;
		while (af.h == i + 1 && bf.h == i + 1)
		{
			if (af.l == bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data - bf.data;
				if (c.data[c.jd].data)
				{
					c.jd++;
				}
				af = a.data[a.frist[i] + ap];
				bf = b.data[b.frist[i] + bp];
				ap++;
				bp++;
			}
			else if (af.l < bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = af.l;
				c.data[c.jd].data = af.data;
				c.jd++;
				af = a.data[a.frist[i] + ap];
				ap++;
			}
			else if (af.l > bf.l)
			{
				c.data[c.jd].h = i + 1;
				c.data[c.jd].l = bf.l;
				c.data[c.jd].data = -bf.data;
				c.jd++;
				bf = b.data[b.frist[i] + bp];
				bp++;
			}
		}
		while (af.h == i + 1)
		{
			c.data[c.jd].h = i + 1;
			c.data[c.jd].l = af.l;
			c.data[c.jd].data = af.data;
			c.jd++;
			af = a.data[a.frist[i] + ap];
			ap++;
		}
		while (bf.h == i + 1)
		{
			c.data[c.jd].h = i + 1;
			c.data[c.jd].l = bf.l;
			c.data[c.jd].data = -bf.data;
			c.jd++;
			bf = b.data[b.frist[i] + bp];
			bp++;
		}
	}
	return c;
}
SYZ syzmul(SYZ a, SYZ b)
{
	SYZ c;
	c.jh = a.jh;
	c.jl = b.jl;
	if (a.jl != b.jh)
	{
		printf("此两个矩阵无法相乘。\n");
		return c;
	}
	int adata[a.jd * a.jl], bdata[b.jd * b.jl];
	syztodata(a, &adata);
	syztodata(b, &bdata);
	for (int i = 0; i < a.jh; i++)
	{
		c.frist[i] = c.jd;
		for (int x = 0; x < b.jl; x++)
		{
			int num = 0;
			for (int y = 0; y < a.jl; y++)
			{
				num += adata[i * a.jl + y] * bdata[y * b.jl + x];
			}
			if (num)
			{
				c.data[c.jd].h = i+1;
				c.data[c.jd].l = x+1;
				c.data[c.jd].data = num;
				c.jd++;
			}
		}
	}
}
void syzprt(SYZ a)
{
	for (int i = 0; i < a.jd; i++)
	{
		printf("第%d行第%d列，数值为%d\n", a.data[i].h, a.data[i].l, a.data[i].data);
	}
}
