#include <stdio.h>
int strlen(char t[])
{
	int len = 0;
	while (t[len] != '\0')
	{
		len++;
		/* code */
	}
	return len;
};
void strconcat(char (*t1)[], char (*t2)[])
{
	//将t2内容连接到t1后面
	int a = strlen(*t1);
	int b = strlen(*t2);
	for (int i = 0; i < b; i++)
	{
		(*t1)[a + i] = (*t2)[i];
		/* code */
	};
};
void strcopy(char (*t1)[], char (*t2)[])
{
	//t1内容复制到t2
	//调用strconcat函数将t1内容连接到t2上。
}
int strcmp(char t1[], char t2[])
{
	//符合返回1,不符合返回0
	int a = strlen(t1);
	int b = strlen(t2);
	if (a != b)
	{
		return 0;
		/* code */
	}
	for (int i = 0; i < a; i++)
	{
		if (t1[i] != t2[i])
		{
			return 0;
			/* code */
		}
		/* code */
	}
	return 1;
};
void substr(char t1[], char (*t2)[], int p, int len)
{
	//取t1中第p个位置开始取len个元素，放入t2
	for (int i = 0; i < len; i++)
	{
		(*t2)[i] = t1[i + p - 1];
		/* code */
	}
}
int main(int argc, char const *argv[])
{
	char a[20];
	printf("输入：");
	scanf("%s", a);
	printf(" 串的长度是：%d \n", strlen(a));

	char b[20];
	printf("输入：");
	scanf("%s", b);
	strconcat(&a, &b);
	printf("合并结果：%s \n", a);

	char c[20];
	printf("输入：");
	scanf("%s", c);
	if (strcmp(a, c) == 1)
	{
		printf("符合。\n");
		/* code */
	}
	else
	{
		printf("不符合。\n");
	}
	char d[20];
	substr(c, &d, 2, 3);
	printf("取得子串：%s  \n", d);

	return 0;
}
