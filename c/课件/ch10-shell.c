#include "stdio.h"
#define N 11
int a[N]={0,9,13,8,2,5,13,7,1,15,11};
int d[3]={5,3,1};

void shell_pass(int R[], int d)
   /*  ��˳���L����һ��ϣ������, ����Ϊd  */
{  int j, k ;
for (j=d+1; j<N; j++)
{   R[0]=R[j] ;        /*  ���ü����ڱ�  */
k=j-d ;
while (k>0 && R[0]<R[k]) 
    { R[k+d]=R[k] ; k=k-d;   }
  R[k+d]=R[0] ;
}
}
void shell_sort(int L[], int dk[], int t)
     /*    ����������dk[0 �� t-1],��˳���L����ϣ������   */
{  int m ;
for (m=0; m<=t; m++)
shell_pass(L, dk[m]);
}
disp()
{int i;
 for(i=0;i<N;i++)
	 printf("%4d",a[i]);
  printf("\n");
}
main()
{disp();
 /*shell_pass(a,5);
 disp();
 shell_pass(a,3);
 disp();
 shell_pass(a,1);
 disp();
*/
shell_sort(a,d,2);
disp();
}