#include"stdio.h" 
int a[9][9]={
	{0,6,4,5,100,100,100,100,100},
	{100,0,100,100,1,100,100,100,100},
	{100,100,0,100,1,100,100,100,100},
	{100,100,100,0,100,2,100,100,100},
	{100,100,100,100,0,100,9,7,100},
	{100,100,100,100,100,100,100,4,100},
	{100,100,100,100,100,100,0,100,2},
	{100,100,100,100,100,100,100,0,4},	
 } ;
int ve[9],vl[9],top[9];
//top
disp(int a[])
{int i;
for(i=0;i<9;i++)
printf("%d  ", a[i]);
printf("\n");
}
main()
{int i,j;
for(i=0;i<9;i++)
  for(j=0;j<9;j++)
   if(a[i][j]>0 && a[i][j]<100)	 
		 top[j]++;
   disp(top);
//topsort
 {   int sp[9]={0},t=0,k,i;
     while(t>=0)
	 {  k=sp[t];
        printf("%d  ",sp[t]);
        t--;
        for(i=0;i<9;i++)
		{
			if(a[k][i]>0 && a[k][i]<100)
			{  top[i]--;
               if(top[i]==0)
			   {t++; sp[t]=i;}
			}
		}
	 }
 }
 printf("\n");
 for(i=1;i<9;i++)
 { ve[i]=-1;
	 for(j=0;j<9;j++)
       if(a[j][i]>0 && a[j][i]<100)
           if(ve[j]+a[j][i]>ve[i])
			   ve[i]=ve[j]+a[j][i];
 }
 disp(ve);
printf("\n\n");
vl[8]=ve[8];
for(i=7;i>0;i--)
 { vl[i]=1000;
	 for(j=0;j<9;j++)
       if(a[i][j]>0 && a[i][j]<100)
           if(vl[j]-a[i][j]<vl[i])
			   vl[i]=vl[j]-a[i][j];
 }
 disp(vl);
printf("\n\n");
for(i=0;i<9;i++)
  if(ve[i]==vl[i])
	  printf("%d  ",i+1);

}