#include "stdio.h"
#define maxsize 100
typedef int datatype;
typedef struct{
       int   i,j;
       datatype v;
    }triple;
typedef struct{
      triple  data[maxsize];
      int rpos[10];
      int  mu,nu,tu;
      }trptb;
main()
{trptb m={{0,0,3,0,3,5,1,1,-1,2,0,2,2,2,1},{0,2,3,5},3,4,5};
 trptb n ={{0,1,2,1,0,1,2,0,-2,2,1,4},{0,1,2,4,4},4,2};
 trptb q={0};
 int ctemp[5]={0},arow,brow,p,tp,k,t,i,ccol;
 q.nu=m.nu;q.nu=n.nu,q.tu=0;
 if(m.tu*n.tu!=0);
 //clrscr();
for(arow=0;arow<m.mu;++arow)
   { for(i=0;i<n.nu;++i)
      ctemp[i]=0;
      q.rpos[arow]=q.tu;
      tp=m.rpos[arow+1];
   for(p=m.rpos[arow];p<tp;++p)
     { brow=m.data[p].j;
       t=n.rpos[brow+1];
       for(k=n.rpos[brow]; k<t;++k)
	{
	  ccol=n.data[k].j;
	  ctemp[ccol]+=m.data[p].v*n.data[k].v;
	 }
    }
     for(ccol=0;ccol<q.nu;++ccol)
	 if(ctemp[ccol]){
	       q.data[q.tu].i=arow;
	       q.data[q.tu].j=ccol;
	       q.data[q.tu].v=ctemp[ccol];
	       q.tu++;
	     }


      }
      for(i=0;i<q.tu;++i)
      printf("%4d  %4d  %4d\n",q.data[i].i,q.data[i].j,q.data[i].v);
      }

