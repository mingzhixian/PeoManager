#include <stdio.h>
#include "sanyuanzu.h"
void randata(int (*data)[])
{

}
int main(int argc, char const *argv[])
{
	int data1[6*6];
	randata(&data1);
	SYZ a=syzinit(data1,6,6);
	int data2[6*6];
	randata(&data2);
	SYZ b=syzinit(data2,6,6);
	SYZ c=syzadd(a,b);
	return 0;
}
