#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct {
  int i,j;
  int e;
}Triple;
typedef struct{
  Triple data[MAXSIZE+1];
  int mu,nu,tu;
} Tsmatrix;
int a,b;   /* 数组行，列数 */

Tsmatrix * creatarray(Tsmatrix *M)
{ int m,n,p=1;
  int c;
  printf("please input the array A:\n");
  for(m=1;m<=a;m++)
    for(n=1;n<=b;n++)
     { scanf("%d",&c);
       if(c!=0)
        {  M->data[p].e=c;
           M->data[p].i=m;
           M->data[p].j=n;
           p++;
        }
     }
  M->tu=p; M->mu=a; M->nu=b;
  printf("原矩阵三元组：\n");
  for(m=1;m<M->tu;m++)
     printf("%3d%3d%3d\t\n",M->data[m].i,M->data[m].j,M->data[m].e);
   printf("\n");
  return M;
}




Tsmatrix * fasttrans(Tsmatrix *M,Tsmatrix *T)
{  
   int p,col,q,t,m;
   int num[100];
   int cpot[100];
   T->mu=M->nu; T->nu=M->mu; T->tu=M->tu;
   if(T->tu!=0)
    {
      for(col=1;col<=M->nu;++col) 
		  num[col]=0;
        for(t=1;t<M->tu;++t)    
			num[M->data[t].j]++;
      cpot[1]=1;
      for(col=2;col<=M->nu;++col)  
		  cpot[col]=cpot[col-1]+num[col-1];
      for(p=1;p<M->tu;++p)
        {  
		   col=M->data[p].j; 
		   q=cpot[col];
           T->data[q].i=M->data[p].j;
           T->data[q].j=M->data[p].i;
           T->data[q].e=M->data[p].e;
           ++cpot[col];
        }
}
   printf("\n转置后:\n");
   for(m=1;m<T->tu;m++)
     printf("%3d%3d%3d\t\n",T->data[m].i,T->data[m].j,T->data[m].e);
   printf("\n"); 
   return T;
}

void  print(Tsmatrix *T,int x,int y)
{  
	int m,n,p=1;
   int d;
   for(m=1;m<=x;m++)
    { printf("\n");
      for(n=1;n<=y;n++)
       { if(T->data[p].i==m&&T->data[p].j==n)
          {  d=T->data[p].e;
             p++;
          }
         else d=0;
         printf("%6d",d);
       }
   }
   printf("\n");
}

void main()
{  Tsmatrix *M,*T;
   M=(Tsmatrix *)malloc(sizeof(Tsmatrix));
   T=(Tsmatrix *)malloc(sizeof(Tsmatrix));
   printf("输入行数和列数:\n");
   scanf("%d%d",&a,&b);         
   M=creatarray(M);     
   printf("创建矩阵：\n");
   print(M,a,b);       
   T=fasttrans(M,T);  
   printf("转后：\n");
   print(T,b,a);
//   getch();
}