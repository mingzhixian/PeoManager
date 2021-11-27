#include <stdio.h>
#include <time.h>
#include <random>
struct Tri
{
	int x,y,ele;
	/* data */
	//单个位置
};
struct TT
{
	Tri data[20];
	int jx,jy,jd=0;
	//jx为矩阵x大小，jd为矩阵非零值数量
	/* data */
};
void set(int (*t)[42])
{
	srand(time(0));
	int data;
	for (int i = 0; i < 6; i++)
	{
		for (int u = 0; u < 7; u++)
		{
			data=rand()%100;
			if (data>52&&data<60)
			{
				(*t)[i*6+u]=data;
				/* code */
			}
		}
	}
	
}
void prt1(int t[])
{
	for (int i = 0; i < 6; i++)
	{
		for (int u = 0; u < 7; u++)
		{
			if (t[6*i+u]>0)
			{
				printf(" %d  ",t[6*i+u]);
				/* code */
			}
			else
			{
				printf("  %d  ",t[6*i+u]);
			}
			
			/* code */
		}
		printf("\n");
		/* code */
	}
	
}
void get (int t[42],TT *san)
{
	san->jx=6;
	san->jy=7;
	for (int i = 0; i < 6; i++)
	{
		for (int u = 0; u < 7; u++)
		{
			if (t[6*i+u]>0)
			{
				san->data[san->jd].x=i;
				san->data[san->jd].y=u;
				san->data[san->jd].ele=t[6*i+u];
				san->jd++;
			}
		}
	}
}
void prt2(TT san)
{
	printf("矩阵有%d行，%d列，其中有值元素有%d个：\n",san.jx,san.jy,san.jd);
	for (int i = 0; i < san.jd; i++)
	{
		printf("第%d行 第%d列 值为%d\n",san.data[i].x+1,san.data[i].y+1,san.data[i].ele);
	}
	
}
void tran (TT san1,TT *san2)    //转置
{
	san2->jx=san1.jy;
	san2->jy=san1.jx;
	for (int i = 0; i < san1.jy; i++)
	{
		for (int y = 0; y < san1.jd; y++)
		{
			if (san1.data[y].y==i)
			{
				san2->data[san2->jd].x=san1.data[y].y;
				san2->data[san2->jd].y=san1.data[y].x;
				san2->data[san2->jd].ele=san1.data[y].ele;
				san2->jd++;
			}
			
		}
		
	}
	
}
void qtran(TT san1,TT *san2)
{
	san2->jx=san1.jy;
	san2->jy=san1.jx;
	san2->jd=san1.jd;
	int num[7],newsite[7];  //num是每列非零个数。mewsite为每列首位非零元素在新三元组表中位置。
	int i,j;
	for (i = 0; i < san1.jy; i++)   //num数组赋值
	{
		num[i]=0;
	};
	for (i = 0; i < san1.jd; i++)
	{
		j=san1.data[i].y;
		num[j]++;
	};
	newsite[0]=0;
	for (i = 1; i < san1.jy; i++)  //newsite赋值
	{
		newsite[i]=newsite[i-1]+num[i-1];
	};
	for (i = 0; i < san1.jd; i++)
	{
		j=san1.data[i].y;//当前元素列数
		san2->data[newsite[j]].x=san1.data[i].y;
		san2->data[newsite[j]].y=san1.data[i].x;
		san2->data[newsite[j]].ele=san1.data[i].ele;
		newsite[j]++;
	}
}
int main(int argc, char const *argv[])
{
	int a[6*7]={0};
	set(&a);
	prt1(a);
	TT san;
	get(a,&san);
	prt2(san);
	TT transan;
	/* tran(san,&transan);
	prt2(transan); */
	qtran(san,&transan);
	prt2(transan);
	return 0;
}
