#define N 5
int c[N][N]={ {0,7,100,100,3},
	      {7,0,6,2,1},
	      {100,6,0,3,10},
	      {100,2,3,0,4},
	      {3,1,10,4,0},};
int f[N],d[N];
int p[N][N];
min()
{int i;
int m=32767,k=-1;
 for(i=0;i<N;++i)
   if(d[i]<m&&f[i]==0)
   k=i,m=d[i];
f[k]=1;
return k;
}
change(int k)
{int i,j;
 for(i=0;i<N;++i)
  if(d[k]+c[k][i]<d[i]&&f[i]==0)
  { d[i]=d[k]+c[k][i];
    j=0;
    while(p[k][j]>0)
     { p[i][j]=p[k][j];
       j++;
     }
     p[i][j]=k+1;
   }
}
disp(int p[N],int k)
{int i=0;
 while(p[i])
 {printf("%d   ",p[i]);
  i++;}
  printf("%d   ",k+1);
}
main()
{int k;
 int i=0;
 //clrscr();
 for(i=0;i<N;++i)
  {d[i]=c[0][i];
     p[i][0]=1;
   }
   f[0]=1;
   for(i=1;i<N;++i)
   { k=min();
  disp(p[k],k);
  printf("   dist=%d\n",d[k]);

   change(k);
} }