#include"stdlib.h"
typedef struct node{
   int data;
   struct node *next;
} quen;

typedef struct{
struct node *f;
struct node *r;
} hq;

enq(hq *q,int x)
{ quen *p;
 p=(quen *)malloc(sizeof(quen));
 p->data=x;
 p->next=0;
 if(q->f==0 ||q->r==0)
   q->r=q->f=p;
 else
   {q->r=p;
    q=p;
   }
}


deq(hq *q)
{int x;
 quen *p;
 if(q->f==0)
  return-1;
 x=q->f->data;
 q->f=q->f->next;
 if(q->f==0)
 q->r=0;
 return x;
}
disp(hq q)
{quen *p=q.f;
 while(p)
   {printf("   %d->",p->data);
    p=p->next;}
  printf("\n");
}
main()
{hq p,
  clrscr();
   p.r=p.f=0;
   enq(&p,1);
   enq(&p,1);

   enq(&p,2);
   enq(&p,199);
   enq(&p,881);
   enq(&p,81);
  disp(p);


}

