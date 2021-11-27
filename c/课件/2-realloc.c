#include"stdio.h"
#include"stdlib.h"
main()
{int i,j;
 int *p1,*p2,*q;
 p1=(int *) malloc(10*sizeof(int));
 p2=(int *) malloc(sizeof(int));
 printf("%x   %x\n",p1,p2);
 printf("%x  %d  \n",p2-p1,p2-p1);
 q=p1;
  for(i=0;i<10;i++)
	  *q++=i;
 p1=(int *)realloc(p1,100*sizeof(int));
 printf("%x   %x\n",p1,p2);
 printf("%x  %d  \n",p2-p1,p2-p1);
 q=p1;
  for(i=0;i<10;i++)
	  printf(" %d\t",*q++);
 
}