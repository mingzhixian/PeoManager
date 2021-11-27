main()
{int a[30]={0},i,j,k=0;
 //clrscr();
 for(i=0;i<7;++i)
   {a[i*(i+1)/2]=1;a[i*(i+1)/2+i]=1;
    for(j=1;j<i;++j)
     a[i*(i+1)/2+j]=a[i*(i-1)/2+j-1]+a[i*(i-1)/2+j];

    }
 for(i=0;i<7;++i)
  { for(j=0;j<i;++j)
     printf("%4d",a[i*(i-1)/2+j]);
      printf("\n");
   }
 }
