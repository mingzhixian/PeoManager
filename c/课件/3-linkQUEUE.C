#include "stdio.h"
#include"stdlib.h"
typedef int Datatype;
typedef struct node
 { Datatype data;
 struct node * next;
}Node;
typedef struct  {
  Node * front,*rear;
}linkqueue;

 InitQueue(linkqueue *q)
{ Node *p=(Node* )malloc(sizeof(Node));
 p->next=0; 
 q->front=q->rear=p;
}

int QueueEmpty(linkqueue * q)
{
 return q->rear==0;
}
EnQueue(linkqueue *q,Datatype x)
{ Node *p=(Node*)malloc(sizeof(Node));
  p->data=x;
  p->next=0;
 q->rear->next=p;
 q->rear=p;
}

Datatype DeQueue(linkqueue *q)
{ Datatype x;
 if (QueueEmpty(q))
 {
  printf("empty!");
  exit(-1);
  }
  x=q->front->next->data;
   q->front=q->front->next;
 return x;
}

void Disp(linkqueue q)
{ Node *p=q.front->next ;
  printf("=====================================\n");
 while(p)
 {	 printf("%4c  ",p->data);
     p=p->next;
 }
 printf("\n=====================================\n");
}

Datatype getfront(linkqueue q)
{
 if (QueueEmpty(&q))
 {
  printf(" empty!");
  exit(-1);
  }
  return q.front->next->data;
}

void main()
{linkqueue *q=(linkqueue* )malloc(sizeof(linkqueue));
 //Node *p=(Node* )malloc(sizeof(Node));
  
InitQueue(q);
 //clrscr();
 printf("a,b,c,d enqueue\n");
 EnQueue(q,'a');
 EnQueue(q,'b');
 EnQueue(q,'c');
 EnQueue(q,'d');
 Disp(*q);
 printf("out1:%c\n",DeQueue(q));
 printf("out2:%c\n",DeQueue(q));
 printf("front data:%c\n",getfront(*q));
}

