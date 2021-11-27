#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct LL
{
	int data = 0;
	LL *next;
};
void push(LL *t, int data) //入栈
{
	LL *p = (LL *)malloc(sizeof(LL));
	p->data = data;
	p->next = t->next;
	t->next = p;
	t->data++; //栈中元素
};
int get(LL *t) //出栈
{
	if (t->data == 0)
	{
		printf("栈中无内容。\n");
		return 0;
	}
	LL *p = (LL *)malloc(sizeof(LL));
	p = t->next;
	t->next = t->next->next;
	int data = p->data;
	free(p);
	t->data--;
	return data;
};
int getsite(int a[2][20],int data) //获取data在a第一行中位置
{
	for (int i = 0; i < 20; i++)
	{
		/* code */
		if (a[0][i]==data)
		{
			/* code */
			return i;
		}
	}
	return 0;
}
void canpop()
{
	printf("输入:(每行每个数字空格隔开)\n");
	int n,d[2][20],is=1,ele=0,top,a[20],v=0;    //n为入栈元素个数,d为检测数据存储,is存储是否合法,ele存储栈中元素个数,top存储栈顶元素,a存储已出栈元素，v为已出栈元素个数
	LL t;  //栈
	scanf("%d",&n);
	for (int i = 0; i < 2; i++)  //保存输入
	{
		for (int u = 0; u < n; u++)
		{
			scanf("%d",&d[i][u]);
		}
	};
	for (int u = 0; u < getsite(d,d[1][0]); u++)//把第一个出栈元素以前的全部入栈
	{
		/* code */
		push(&t,d[0][u]);
		a[0]=d[0][u];
		v++;
		ele++;
	}
	for (int i = 1; i < n; i++) //从第二个开始检测
	{
		/* code */
		if (ele==0)  //如果站内元素为0,说明当前为进栈后直接出栈
		{
			/* code */
			continue;
		}
		top=get(&t);   //如果站内元素不为0,则获取栈顶元素
		ele--;
		int s1=getsite(d,d[1][i]),s2=getsite(d,top);
		if (s1>s2)  //如果要出栈的元素在栈顶元素之后则将之间的元素入栈
		{
			/* code */
			for (int u = s1; u < s2; u++) //先将取出栈顶放回
			{
				/* code */
				for (int v = 0; v < s2; i++)
				{
					/* code */
				}
				
				push(&t,u);
				ele++;
			}
			
		}
		else if (s1==s2)  //相同说明正好是栈顶元素出栈
		{
			/* code */
			continue;
		}
		else  //如果出栈元素在栈顶元素之前，因栈顶元素还没出栈所以不对
		{
			is=0;
			break;
		}
	}
	if (is==0)
	{
		/* code */
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	
}
int main(int argc, char const *argv[])
{
	canpop();
	return 0;
}