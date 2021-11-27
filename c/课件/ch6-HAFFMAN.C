findmin(int d[][4],int k)
{int min,i,l;
  min=1000;l=-1;
  for(i=0;i<=k;++i)
   if(min>d[i][0] &&d[i][1]==0)
      min=d[i][0],l=i;
   return l;
}
record(int d[][4],int k,int i,int f)
{d[k][0]=d[k][0]+d[i][0];
 d[i][1]=k;
 if(f==0)
    d[k][2]=i;
 else
    d[k][3]=i;
}

disp(int d[][4],int k)
{int i ,j;
  for(i=0;i<=k;++i)
    {for(j=0;j<4;++j)
      printf("%4d",d[i][j]);
      printf("\n");
}
}
typedef struct {int s[5];
	   int top;}stack;

push(stack *st,int e)
{st->top++;
 st->s[st->top]=e;
}
pop(stack *st)
{st->top--;
 return st->s[st->top+1];
 }

 disp1(stack st)
  {while(st.top>=0)
    printf("%d ",pop(&st));
    printf("\n");

  }

code(stack *st,int data[][4],int i)
 {int j,k,l;
  st->top=-1;
  do
   { k=data[i][1];
    if(i==data[k][2])
      push(st,0);
    else
      push(st,1);
    i=k;  }while(data[i][1]>0);


 }
main()
{int data[15][4]={{5},{29},{7},{8},{14},{23},{3},{11}};
  int i,j,k,l;
 clrscr();
 for(k=8;k<15;++k)
  {l=findmin(data,k-1);
    record(data,k,l,0);
   disp(data,k);
   getche();
   l=findmin(data,k-1);
   record(data,k,l,1);
   disp(data,k);
   getche();
  }
 {stack st;
  int i,j,k;
  for(i=0;i<8;++i)
    { code(&st,data,i);
      printf("\n%d  %d:",i,data[i][0]);
      disp1(st);}

 }

}


