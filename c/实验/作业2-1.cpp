#include <stdio.h>
#include <string.h>
typedef struct STR
{
	char data[100];
	int ele = 0;
};
int insert(STR *a, char data[], int site)
{
	int ele = strlen(data);
	if (ele + a->ele > 100) //判断是否超量程
	{
		printf("超量成。\n");
		return 0;
	}
	for (int i = a->ele; i >= site; i--) //后移
	{
		a->data[i + ele] = a->data[i];
	}
	for (int i = site; i < site + ele; i++) //插入
	{
		a->data[i] = data[i - site];
		a->ele++;
	}
	return 1;
}
int index(STR a, char data[])
{
	//默认方法，暴力查找
	int ele = strlen(data);
	for (int i = 0; i < a.ele; i++)
	{
		if (a.data[i] == data[0])
		{
			int is = 1;
			for (int x = 1; x < ele; x++)
			{
				if (a.data[i + x] != data[x])
				{
					is = 0;
					break;
				}
			}
			if (is == 1)
			{
				return i + 1;
			}
		}
	}
	return -1;
}
int strreplace(STR *a, char data1[], char data2[])
{
	//data1为被替换值，data2为替换值
	int site = index(*a, data1);
	if (site==-1)
	{
		printf("被替换值不存在。\n");
		return 0;
	}
	int ele1 = strlen(data1);
	int ele2 = strlen(data2);
	if (ele1 != ele2)
	{
		printf("替换值与被替换值大小不同，请检查。\n");
		return 0;
	}
	for (int i = site - 1; i < site + ele1 - 1; i++)
	{
		a->data[i] = data2[i - site + 1];
	}
	return 1;
}
void substr(STR a, int site, int ele, char (*data)[])
{
	//site是所取子串起始位置，ele为所取子串长度。
	for (int i = site-1; i < site-1+ele; i++)
	{
		(*data)[i-site+1]=a.data[i];
	}
}
void prt(STR a)
{
	for (int i = 0; i < a.ele; i++)
	{
		printf("%c ", a.data[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	STR a;
	char b[10]={};
	char c[10]={};
	char d[10]={};
	{ //插入测试
		printf("插入测试。");
		scanf("%s", b);
		insert(&a, b, 0); //在第0个之后插入
		scanf("%s", b);
		insert(&a, b, 2); //在第2个之后插入
		prt(a);
	}
	{ //查找测试
		printf("查找测试");
		scanf("%s", b);
		printf("%d\n", index(a, b)); //如果找不到返回-1,找到了返回开始位置,如果有多个默认只返回第一处
	}
	{ //替换测试
		printf("替换测试");
		scanf("%s", b);
		scanf("%s", c);
		strreplace(&a, b, c);
		prt(a);
	}
	{  //取子串
		substr(a, 2, 3, &d);
		printf("取子串测试：%s\n",d);
	}
	return 0;
}
