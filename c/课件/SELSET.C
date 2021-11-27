int a[]={1,32,34,45,456,6,56,567,5000};
part(m,p)
int m,p;
{int i,v;
 v=a[m];i=m;
 do
 { do {++i;}while(a[i]<v);

   do {--p;}while(a[p]>=v);
   if(i<p)
     {int t;
     t=a[i],a[i]=a[p],a[p]=t;}
     else
      break;

    a[m]=a[p];a[p]=v;
    }while (1);
    return p;

 }
quick (p,q)
int p,q;
{int j;
if(p<q)
  {j=q+1;
  j=part(p,j);
  quick(p,j);
  quick(j+1,q);
  disp();
   }

}
disp()
{int i;
  for(i=0;i<8;++i)
    printf("%d  ",a[i]);
    printf("\n");}
main()
{ int p,q;
  quick(0,8);

}