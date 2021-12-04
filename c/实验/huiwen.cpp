#include <stdio.h>
#include "dui.h"
DUI huiwen(int a, int b)
{
	DUI final;
	while (a <= b)
	{
		int x = a / 100;
		int tmp = x %10;
		x=x/10;
		x = tmp*10;
		int y = a % 100;
		tmp=y%10;
		y=y/10;
		y=tmp*10+y;

		if (0 < y < 13)
		{
			if (y == 2)
			{
				int z = a % 4;
				if (z)
				{
					z = 28;
				}
				else
				{
					z = 29;
				}
				if (0 < x < z)
				{
					duipush(&final, a);
					continue;
				}
			}
			else if (y == 4 || y == 6 || y == 9 || y == 11)
			{
				if (0 < x < 31)
				{
					duipush(&final, a);
					continue;
				}
			}
			else
			{
				if (0 < x < 32)
				{
					duipush(&final, a);
					continue;
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
