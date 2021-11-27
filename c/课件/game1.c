#include "stdio.h"
#include "stdlib.h"
int n=200,c=0,no;
int dx=2;
main()
{int i,data[1000];
  srand(time(0)); 
for(i=0;i<1000;i++)
 {data[i]=rand()%2;
 printf("%d ",data[i]);}
 printf("\n");
 no=0;
 for(i=0;i<1000;i++)
 {//printf("%d ",data[i]);
  no++;
	 if(data[i]==0)
 {
   if(data[i+1]==0)
   {c=c-dx;
    dx+=2;
   }
   else
   {c=c+dx;
   dx-=2;}
 }
  else
  { if(data[i+1]==0)
  { c=c+dx;dx-=2;}
     else
	 { c=c-dx;dx+=2;}
  }
  printf("%d %d %d  ",i,dx,c);
 if(c==0)
  //break;
 {printf("\n no=%d\n",no);no=0 ;dx=2;}
  getche();
}
}