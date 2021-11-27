
/* #include<iostream.h>
int maxsum(int a[],int n,int &besti,int &bestj){  
    int sum=0;  
    int i,j,k; 
	int sumij=0;
    for(i=1;i<=n;i++)  
	{    //int sumij=0;
		for(j=i;j<=n;j++)  
        {  
            int sumij=0;  
            for(k=i;k<=j;k++)sumij+=a[k];       
            //sumij+=a[j];
			if( sumij>sum){  
                sum=sumij;  
                besti=i;  
                bestj=j;                 
            }        
        }  
	}
      return sum;  
    }  
int main()  
{  
    int a[] = {0,-2,11,-4,13,-5,-2};  
    int i,j,n,m;
    for(i=1; i<7; i++)  
    {  
        cout<<a[i]<<" ";  
    }  
  
    cout<<endl; 
	m=maxsum(a,6,i,j);
    cout<<"最大连子段和:"<<m<<endl;  
    cout<<"i-j:   "<<i<<"  -  "<<j<<endl;  
  
    return 0;  
} 
*/

	/*
#include <iostream.h>     
int MaxSubSum(int *a,int left,int right);  
int MaxSum(int n,int *a);  
  
int main()  
{  
    int a[] = {-2,11,-4,13,-5,-2};  
  
    for(int i=0; i<6; i++)  
    {  
        cout<<a[i]<<" ";  
    }  
  
    cout<<endl;  
    cout<<"最大连子段和:"<<MaxSum(6,a)<<endl;  
  
    return 0;  
}  
  
int MaxSubSum(int *a,int left,int right)  
{     
    int sum = 0;  
    if(left == right)  
    {  
        sum = a[left]>0?a[left]:0;  
    }  
    else  
    {  
        int center = (left+right)/2;  
        int leftsum = MaxSubSum(a,left,center);  
        int rightsum = MaxSubSum(a,center+1,right);  
  
        int s1 = 0;  
        int lefts = 0;  
        for(int i=center; i>=left;i--)  
        {  
            lefts += a[i];  
            if(lefts>s1)  
            {  
                s1=lefts;  
            }  
        }  
  
        int s2 = 0;  
        int rights = 0;  
        for( i=center+1; i<=right;i++)  
        {  
            rights += a[i];  
            if(rights>s2)  
            {  
                s2=rights;  
            }  
        }  
        sum = s1+s2;  
        if(sum<leftsum)  
        {  
            sum = leftsum;  
        }  
        if(sum<rightsum)  
        {  
            sum = rightsum;  
        }  
  
    }  
    return sum;  
}  
  
int MaxSum(int n,int *a)  
{  
    return MaxSubSum(a,0,n-1);  
}  
*/

/*
 #include"iostream.h"

int max = 0;
int a[7]={0,-2,11,-4,13,-5,-2};
int b[7];
int maxsum(int b[],int n);
main()
{	maxsum(b,7);
	for(int i=0;i<7;i++)
     cout<<b[i]<<"   ";
	cout<<endl<<max<<endl;
}
maxsum(int b[],int n)
{

for(int i = 1; i <n; ++i)
 {
   
	if(b[i-1]>0)
   {
     b[i] = b[i-1]+a[i];
   }else if(a[i]>0)
	{
     b[i] = a[i];
   }
   if(b[i]>max)
     max = b[i];
 }
return max;
} */




#include<iostream>
using namespace std;
int d[5][5]={
{0,0,-2,-7,0},
{0, 9,2,-6,2},
{0,-4,1,-4,1},
{0,-1,8, 0,-2}
};

int maxsub(int a[],int n)
{
int i,sum=0,b=0;
   for(i=0;i<=n;i++)
{
    if(b>0)
		b+=a[i];
    else 
	   b=a[i];
    if(b>sum)sum=b;
 }
  return sum;
}

int main()
{
	int b[5];
int n=4,i,k,j,sum,maxsum,r1,r2,c1,c2;
 maxsum=0;
for(i=0;i<=n;i++)
{ for(j=0;j<n;j++)
   b[j]=0;
  for(j=i;j<=n;j++)
 { for(k=0;k<=n;k++)
   b[k]+=d[j][k];
    sum=maxsub(b,n);
   if(sum>maxsum)
    maxsum=sum;
 }
}
   printf("maxsum %d\n",maxsum);
  
}


