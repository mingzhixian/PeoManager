#include<stdio.h>
#define N1 11
#define N2 10
void printmaze();
int getpath(int maze[N1][N2])
{
   int stack[N1*N2][2];
   int i,x=1,y=1,ok,top=0;
   stack[top][0]=x;
   stack[top][1]=y;
   while (1)
   {ok=0;
    if (maze[x][y+1]==0)
   {y=y+1;ok=1;}
   else
      if (maze[x+1][y]==0)
	  {x=x+1;ok=1;}
      else
        if (maze[x][y-1]==0)
		{y=y-1;ok=1;}
        else
           if (maze[x-1][y]==0)
		   {x=x-1;ok=1;}
   if (!ok)
   {maze[x][y]=-3;
     printmaze(maze);
    getche();

    top--;
    if (top==0)
	{
     printf("no road\n");
     return 0;
	}
    x=stack[top][0];
    y=stack[top][1];
   }
   else
   {
   maze[x][y]=2;
   top++;
   stack[top][0]=x;
   stack[top][1]=y;
    printmaze(maze);
    getche();

   if (x==N1-2&&y==N2-2)
   {
    printf("path:\n");
    for(i=0;i<top;i++)
	{
      printf("(%d,%d)-->",stack[i][0],stack[i][1]);
      if((i+1)%5==0)
        printf("\n");
	}
    printf("(%d,%d)\n",stack[top][0],stack[top][1]);
   return 1;
}
}
}
}

void printmaze(maze)
int maze[N1][N2];
{
int i,j;
printf("arrar:\n");
for (i=0;i<N1;i++)
{
for (j=0;j<N2;j++)
printf("%2d",maze[i][j]);
printf("\n");
}
}

main()
{
int A[N1][N2]=
{
1,1,1,1,1,1,1,1,1,1,
1,0,0,1,0,0,0,1,0,1,
1,0,0,1,0,0,0,1,0,1,
1,0,0,0,0,1,1,0,1,1,
1,0,1,1,1,0,0,1,0,1,
1,0,0,0,1,0,0,0,0,1,
1,0,1,0,0,0,1,0,1,1,
1,0,1,1,1,1,0,0,1,1,
1,1,1,0,0,0,1,0,1,1,
1,1,1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1};
printmaze(A);

getpath(A);
}