#include"stdio.h"
int a[]={0,49,38,65,97,76,13,27,49,55,04};
prt(int n)
{int i;
 for(i=0;i<n;i++)
	putchar(' ');
}
disp(int l,int h)
{int i,j,k=1,n,m=1;
  while(k<h-l+1)
	k=k*2;
   n=l;
  ;
  for(j=0;j<k;j++)
  {prt(40-4*m);
   for(i=1;i<=m;i++)
	  {if(n>h) return;
       printf("%d",a[n]); prt((k-j));
       n++;}
    printf("\n");
    m=m*2;
  }
 
}
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
   disp(1,m);
   }
   for(i=m;i>0;--i)
     {t=a[1],a[1]=a[i],a[i]=t;
      heapadj(1,i-1);
  }
  }
  main()
  {disp(1,11);
   heapsort(10);
   disp(1,11);

    }