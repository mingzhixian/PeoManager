#include"stdio.h"
#include "math.h"
//int a[]={70,8,90,62,23,12,56};int b[10];
    int a[]={0,49,38,65,97,76,13,27,49,55,04};
 prt(int n)
 {int i;
  for(i=0;i<n;i++)
    printf(" ");
 }
 disp(int low,int high)
  {int i;
   for(i=low;i<high;++i)
    printf("%d  ",a[i]);
    printf("\n------\n");
    }
 disp1(int low,int high)
  {int i,r=2,t;
   t=sqrt(high-low)+1;
   t=pow(2,t);  
   prt(18+t);
   for(i=low;i<high;++i)
   { printf("%2d",a[i]);
     prt(t);
	 if(i==r-1)
	 {r=r*2;
	  t=t/2;
	  printf("\n"); 
	  prt(20+t);
      } 
   }
   printf("\n\n");
   
 }
/*
  merge(int low,int mid,int high)
{int i,j,k,n;
i=low,k=low,j=mid+1;
while(i<=mid && j<=high)
  {if(a[i]<=a[j])
    b[k]=a[i],i++;
  else
    b[k]=a[j],j++;
  k++;
  }
if(i>mid)
  for(n=j;n<=high;n++)
       b[k]=a[n],k++;
else
  for(n=i;n<=mid;n++)
     b[k]=a[n],k++;

     for(k=low;k<=high;++k)
     a[k]=b[k];
  }
  mergesort(int low,int high)
  {int mid;
   if(low<high)
   {mid=(low+high)/2;
   mergesort(low,mid);
   mergesort(mid+1,high);
   merge(low,mid,high);
   disp(0,7);}
  }
  */
  heapadj(int l,int m)
  {int i,j,k,t;
   t=a[l];
   i=2*l;
   while(i<=m)
      { if(i+1<=m&&a[i]>a[i+1])
	    i++;
	if(t<a[i]) break;
    else
	a[l]=a[i],a[i]=t,l=i;
	i=l*2;
	t=a[l];
	}
  }
  heapsort(int m)
   {int i,t;
   for(i=m/2;i>0;--i)
   {heapadj(i,m);
   disp1(1,11);}
   printf("\n heapsort:\n");
   for(i=m;i>0;--i)
     {t=a[1],a[1]=a[i],a[i]=t;
      heapadj(1,i-1);
	  disp1(1,i);
  }
  }
  main()
  {/*int low,high;
    low=0;
    high=6;
    mergesort(low,high);
    disp(low,high); */
    int a[]={0,49,38,65,97,76,13,27,49,55,04};
   // clrscr();disp(1,11);
     heapsort(10);
     disp(1,11);

    }