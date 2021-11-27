#include "stdio.h"
#define max 1000
typedef struct {char space[max];
        int top;
        }stack;
stack st;
/* + - * ( ) # */
char b[6]="+-*()#";
char a[6][6]={{'>','>','<','<','>','>'},
         {'>','>','<','<','>','>'},
         {'>','>','>','<','>','>'},
         {'<','<','<','<','=','>'},
         {'>','>','>','>','=','>'},
         {'<','<','<','<','<','='}};

push(stack *s,char e)
{s->top++;
s->space[s->top]=e;
}

pop(stack *s)
{char e;
 e=s->space[s->top];
 s->top--;
 return e;
}

getst(stack s)
{return s.space[s.top];
}

findop(char b[6],char c)
{int i;
 for(i=0;i<6;++i)
  if(b[i]==c)
   return i;
   return -1;
   }

 char  getop(char a[6][6],int i,int j)
  {return a[i][j];
    }

 oper(char x,char y,char c)
 {char z;
   x=x-'0';
   y=y-'0';
  switch(c)
  { case '+':
     z=x+y;
     break;
  case '-':
     z=x-y;
     break;
  case '*':
     z=x*y;
     break;
    };
   return z;
 }
main()
{stack opd,op;
 char c,f,o;
 int d,i,j;
 int x,y;
 op.top=-1;
 opd.top=-1;
 push(&op,'#');
 printf("\n");
 c=getchar();
 while(!(c=='#'&& getst(op)=='#'))
  {  d=findop(b,c);
    if(d==-1)
    {push(&opd,c);c=getchar();}
    else
     {f=getst(op);
     i=findop(b,f);
     j=findop(b,c);
     o=getop(a,i,j);
    switch(o)
    { case '>':
     y=pop(&opd);
     x= pop(&opd);
     x=oper(x,y,f);
      push(&opd,x+'0');
     pop(&op);
     break;
      case '<':
    push(&op,c);
    c=getchar();
    break;
      case '=':
    pop(&op);
    c=getchar();
    break;
      };
     }
     }
  x=pop(&opd);
 printf("\nresult=%d",x-'0');

}
