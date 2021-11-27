#include"stdlib.h"
#define N 5
int k;
typedef struct { int i,j,v;}tp;
chan1(tp t[],tp s[])
{int i,j,l=0;
 for(i=0;i<k;++i)
   for(j=0;j<k;++j)
     if(t[j].j==i)
    s[l].i=t[j].j,s[l].j=t[j].i,s[l].v=t[j].v,l++;
  }
chan2(tp t[],tp s[])
  {int num[N]={0},cpot[N]={0};
   int i,l;
   for(i=0;i<k;++i)
     num[t[i].j]++;
   for(i=1;i<N;++i)
     cpot[i]=cpot[i-1]+num[i-1];
   printf("\n");
   for(i=0;i<N;++i)
     printf("%4d",num[i]);
    printf("\n");
    for(i=0;i<N;++i)
     printf("%4d",cpot[i]);
  for(i=0;i<k;++i)
    { l=cpot[t[i].j];
      s[l].i=t[i].j,s[l].j=t[i].i,s[l].v=t[i].v;
      cpot[t[i].j]++;}
 }
disp(tp t[])
{int i;
   for(i=0;i<k;++i)
     printf("%d  %d  %d\n",t[i].i,t[i].j,t[i].v);
}

main()
{int a[N][N]={0},i,j,v;
 tp t[15]={0},s[15]={0};
 //clrscr();
 for(k=1;k<10;++k)
  {i=random(5);
   j=random(5);
   v=random(100);
   a[i][j]=v;}
  k=0;
  for(i=0;i<N;++i)
    {for(j=0;j<N;++j)
      { printf("%4d",a[i][j]);
      if(a[i][j]>0)
       {t[k].i=i,t[k].j=j,t[k].v=a[i][j];
      k++;}
     }
     printf("\n");
    }
  disp(t);
  chan1(t,s);
  printf("\n--------------\n");
  disp(s);
 chan2(t,s);
 printf("\n");
 disp(s);
 getche();
}
