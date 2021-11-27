#include <stdio.h>
#include <malloc.h>
void one ()
{
	char *p=(char *)malloc(sizeof(char));
	scanf("%c",p);
	//p是一个指针变量，*p表示指针所存地址的对应内容，p是指针所存地址，&p是指针本身地址
	printf("\n%c\n ",*p);
}
void two()
{
	int *p=(int *)malloc(sizeof(int));
	int a[5];
	int *q=a;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d",&p[i]);
		/* code */
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d \n",*(p+i));
		/* code */
	}
}
void three()
{
	int *p;
	int a=8;
	p=&a;  //*p=a;不可以
	printf("%d\n%d\n%d\n%d\n",*p,a,p,&a);
}
void four(int &a)  //引用
{
	/* - 调用函数传参数方式:
	1. 传数据(相当于函数中定义a,然后赋值,与外部无关系)
	2. 传地址(指针)(传递的是地址,根据地址找到外部值)
	3. 传外号(引用)(传递的是外部值的外号,直接修改外部值) */
	printf("%d\n",a);
	a++;
}
int main(int argc, char const *argv[])
{
	//one();

	//two();

	//three();

	/* int c=6; 
	four(c);
	printf("%d\n",c);
	return 0; */
}
