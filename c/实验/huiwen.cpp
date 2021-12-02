#include <stdio.h>
#include "zhan.h"
#include "dui.h"
DUI huiwen(int a, int b)
{
	DUI final;
	while (a <= b)
	{
		int x=a/100;
		int y=a-100*x;
		if (0<y<13)
		{
			if (y==2)
			{
				int z=a/4;
				z=29-(a-4*z);
				if (0<x<z)
				{
				}
				
			}
			
		}
		
		a++;
	}
	return final;
}
int main(int argc, char const *argv[])
{
	int a = 2000;
	int b = 2100;
	printf("今天是20211202,是回文日哦，很难遇到哦，下面是%d至%d年所有的回文日，所以说不好遇到，因此不能有烦恼！！！", a, b);
	return 0;
}
