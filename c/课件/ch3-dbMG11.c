#include<stdio.h>
#define N1 11
#define N2 10
struct {
   int sp[N1*N2][2];
   int top;
}s;


void printmaze(maze)
int maze[N1][N2];
{
int i,j;
printf("arrar:\n");
for (i=0;i<N1;i++)
{
for (j=0;j<N2;j++)
printf("%3d",maze[i][j]);
printf("\n");
}
}

main()
{int x,y,k,ok;
int a[N1][N2]=
{
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,0,0,-1,0,0,0,-1,0,-1,
-1,0,0,-1,0,0,0,-1,0,-1,
-1,0,0,0,0,-1,-1,0,-1,-1,
-1,0,-1,-1,-1,0,0,-1,0,-1,
-1,0,0,0,-1,0,0,0,0,-1,
-1,0,-1,0,0,0,-1,0,-1,-1,
-1,0,-1,-1,-1,-1,0,0,-1,-1,
-1,-1,-1,0,0,0,-1,0,-1,-1,
-1,-1,-1,0,0,0,0,0,0,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
s.top=0;

//clrscr();
s.sp[s.top][0]=3;
s.sp[s.top][1]=2;
a[3][2]=1;
printmaze(a);
while( s.top>=0)
{ x=s.sp[s.top][0];
  y=s.sp[s.top][1];
  s.top--;
  ok=0;
  k=a[x][y];
  if(x==N1-2 &&y==N2-2)
       break;
  if(a[x][y+1]==0)
   {a[x][y+1]=k+1;
    ok=1;
    s.top++;
    s.sp[s.top][0]=x;
    s.sp[s.top][1]=y+1;
    }
   if(a[x+1][y]==0)
   {
    a[x+1][y]=k+1;
    ok=1;
    s.top++;
    s.sp[s.top][0]=x+1;
    s.sp[s.top][1]=y;
    }
  if (a[x][y-1]==0)
    {a[x][y-1]=k+1;
    ok=1;
    s.top++;
    s.sp[s.top][0]=x;
    s.sp[s.top][1]=y-1;
    }
   if(a[x-1][y]==0)
    {a[x-1][y]=k+1;
    ok=1;
    s.top++;
    s.sp[s.top][0]=x-1;
    s.sp[s.top][1]=y;
    }
  if(ok==1)
  k++;
}
printmaze(a);
x=N1-2;
y=N2-2;

while(k>1)
{k=a[x][y];
printf("%d  %d  %d\n",x,y,a[x][y]);
  if(a[x-1][y]==k-1)
   { x--;continue;}

  if(a[x][y-1]==k-1)
   {y--;continue;}
  if(a[x+1][y]==k-1)
    {x++;continue;}
  if(a[x][y+1]==k-1)
    {y++;continue;}
  }

}
