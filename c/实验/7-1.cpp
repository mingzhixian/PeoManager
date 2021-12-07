#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define ListMax 50 //表最大长度
#define DataMax 10 //数据最大长度
typedef struct info
{
	int key;
	char data[DataMax];
};
typedef struct List
{
	info *data;
	int ele;
} * LList;
LList InitList() //顺序表初始化
{
	List *a = (List *)malloc(sizeof(List));
	a->ele = 0;
	a->data = (info *)malloc(ListMax * sizeof(info));
	return a;
}
void CreateList(LList a) //顺序表创建
{
	char data[DataMax];
	int key;
	for (int i = 0; i < 4; i++)
	{
		printf("数据：");
		scanf("%s", data);
		printf("key：");
		scanf("%d", &key);
		for (int x = 0; x < strlen(data); x++)
		{
			a->data[a->ele].data[x] = data[x];
		}
		a->data[a->ele].key = key;
		a->ele++;
	}
}
void DispList(LList a) //遍历
{
	int i;
	for (i = 0; i < a->ele; i++) //关键字遍历
		printf("%d ", a->data[i].key);
	printf("\n");
	for (i = 0; i < a->ele; i++) //关键字信息遍历
		printf("%s ", a->data[i].data);
	printf("\n");
}
int SearchListNormal(LList a, int s) //常规查找
{
	for (int i = 0; i < a->ele; i++) //关键字遍历
	{
		if (a->data[i].key == s)
		{
			return i + 1;
		}
	}
	return -1;
}
int SearchListKey(LList a, int s) //岗哨查找
{
	int i;
	a->data[a->ele].key = s;
	for (i = 0; a->data[i].key != s; i++);
	if (i == a->ele)i = -2;
	return i+1;
}
int SearchListTwo(LList a,int s)  //二分查找
{
	//输入时是有序的表
	int end=a->ele-1;
	int start=0;
	int mid;
	while (start<=end)
	{
		mid=start+(end-start)/2;
		if (a->data[mid].key>s)
		{
			end=mid-1;
		}
		else if (a->data[mid].key<s)
		{
			start=mid+1;
		}
		else
		{
			return mid+1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	LList a = InitList();
	CreateList(a);
	DispList(a);
	printf("岗哨（查得到）%d\n",SearchListKey(a,3));
	printf("岗哨（查不到）%d\n",SearchListKey(a,8));
	printf("常规（查得到）%d\n",SearchListNormal(a,3));
	printf("常规（查不到）%d\n",SearchListNormal(a,8));
	printf("二分（查得到）%d\n",SearchListTwo(a,3));
	printf("二分（查不到）%d\n",SearchListTwo(a,8));
	return 0;
}
