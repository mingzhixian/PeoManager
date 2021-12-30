#include <stdio.h>
#include <malloc.h>
#define keyEle 11  //数据总大小
#define hasiEle 13 //哈希表大小
#define hasikey 11 //求取key时mod值
typedef struct DATA
{
	int IsData[hasiEle] = {0};
	char data[hasiEle][20];
} * TDATA;
int GetNoHave(DATA a, int key)
{
	key = key % hasikey;
	if (a.IsData[key] == 0)
	{
		return key;
	}
	int x = key, y = key;
	while (true)
	{
		x++;
		if (x < hasiEle && a.IsData[x] == 0)
		{
			return x;
		}
		y--;
		if (y > 0 && a.IsData[y] == 0)
		{
			return y;
		}
	}
}
void prt(DATA a)
{
	for (int i = 0; i < hasiEle; i++)
	{
		if (a.IsData[i] != 0)
		{
			printf("哈希表第%d个，存储值为%s\n", i + 1, a.data[i]);
		}
	}
}
TDATA Init(int key[])
{
	TDATA b = (TDATA)malloc(sizeof(DATA));
	for (int i = 0; i < keyEle; i++)
	{
		int z = GetNoHave(*b, key[i]);
		printf("输入下一个，关键值为%d:\n", key[i]);
		scanf("%s", b->data[z]);
		b->IsData[z] = key[i];
	}
	return b;
}
int Find(DATA a, int key)
{
	int hkey = key % hasikey, step = 0;
	step++;
	if (a.IsData[hkey] == key)
	{
		printf("key为%d，值为%s\n", key, a.data[hkey]);
		return step;
	}
	int x = hkey, y = hkey;
	while (true)
	{
		x++;
		if (x < hasiEle)
		{
			step++;
			if (a.IsData[x] == key)
			{
				printf("key为%d，值为%s\n", key, a.data[hkey]);
				return step;
			}
		}
		y--;
		if (y > 0)
		{
			step++;
			if (a.IsData[y] == key)
			{
				printf("key为%d，值为%s\n", key, a.data[hkey]);
				return step;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[keyEle] = {47, 7, 29, 11, 16, 92, 39, 22, 8, 3, 7};
	TDATA z = Init(a);
	prt(*z);
	int allstep = 0;
	for (int i = 0; i < keyEle; i++)
	{
		allstep += Find(*z, a[i]);
	}
	printf("总步数: %d,平均查找所需步数:%.2f (保留两位小数)\n",allstep,(float)allstep/keyEle);
	return 0;
}
