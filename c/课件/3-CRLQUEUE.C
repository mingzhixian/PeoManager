#include "stdio.h"
#define QueueSize 100
typedef int DataType;
typedef struct queuenode {
 int front;
 int rear;
 int count;
 DataType data[QueueSize];
}CirQueue;
 InitQueue(CirQueue *q)
{
 q->front=q->rear=0;
 q->count=0;
}
int QueueEmpty(CirQueue * q)
{
 return q->count==0;
}
int QueueFull(CirQueue * q)
{
 return q->count==QueueSize;
}
EnQueue(CirQueue *q,DataType x)
{
 if (QueueFull(q))
 {
  printf("queue is full,can not enqueuen");
  exit(-1);
  }
 else
 {
  q->count++;
  q->data[q->rear]=x;
  q->rear=(q->rear+1)%QueueSize;
  }
}

DataType DeQueue(CirQueue *q)
{ DataType x;
 if (QueueEmpty(q))
 {
  printf("Queue is empty, can ont  dequeue");
  exit(-1);
  }
  x=q->data[q->front];
   q->count--;
   q->front=(q->front+1) % QueueSize;
 return x;
}

void Disp(CirQueue * p)
{ int i;
 printf("=====================================\n");
 printf("len:%d data\n",p->count);
 for ( i=0;i<p->count;i++)
  printf("%d -> %c\n",i,p->data[i]);
 printf("=====================================\n");
}

DataType QueueFront(CirQueue *q)
{
 if (QueueEmpty(q))
 {
  printf("Queue is empty, can not dequeue");
  exit(-1);
  }
  return q->data[q->front];
}

void main()
{CirQueue *q=(CirQueue*)malloc(sizeof(CirQueue));
 InitQueue(q);
 //clrscr();
 printf("a,b,c,d enqueue\n");
 EnQueue(q,'a');
 EnQueue(q,'b');
 EnQueue(q,'c');
 EnQueue(q,'d');
 Disp(q);

 printf("out1:%c\n",DeQueue(q));
 printf("out2:%c\n",DeQueue(q));
 printf("front data:%c\n",QueueFront(q));
}

