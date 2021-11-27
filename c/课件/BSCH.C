#define N 7
int a[]={1,3,4,5,7,9,10};
bsch(int x)
{int l,h,m;
 l=0,h=N-1;

 while(l<=h)
 {m=(l+h)/2;
 if(a[m]==x)
     return m;
  else if(a[m]>x)
	 h=m-1;
       else
	 l=m+1;
  }
  return -1;
}
main()
{int l;
l=bsch(6);
if(l>=0 )
   printf("find:%d", l);
else
  printf("\n not find!");
}



