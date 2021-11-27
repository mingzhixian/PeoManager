#include "stdio.h"
/*结点的定义*/
struct link
{	int data ;	                /*数据域*/
	struct link *next;		    /*指针域*/
 };
/*链表操作*/
struct link *create( void )         /*创建链表*/
{	struct link *head=NULL, *new, *tail;
   	int count = 0;                   /*链表中的结点个数(初值为0)*/
	while(1)
	{	new = (struct link *)malloc(sizeof(struct link));/*生成新结点*/
		printf("input the data(-1 to end) no.%d:", count+1);
		scanf("%d", &new->data);     /*结点数据域输入数据*/
		new->next=0;                 /*结点指针域设置为空*/
		if(new->data == -1)          /*-1为链表创建结束标志*/
		{	free(new);               /*释放最后申请的结点空间*/
			return head;             /*返回头指针*/
		}
		else
		{	count++;           	  	 /*结点个数加1*/
			if(count == 1)
				head = tail = new;   /*第一个结点, 置头指针*/
			else
			{	tail->next = new;    /*新结点插入到链表尾部*/
				tail = new;            /*设置新的尾结点*/
			}
		}
	}
}

struct link *insert(struct link *head, int x, int k)
{	 struct link *p, *new;
     int j;
     new=(struct link *)malloc(sizeof(struct link));   /*生成新结点*/
     new->data = x;
     new->next = 0;
     if(head == 0)
		 head=new;                         /*将新结点插入到空链表中*/
     else
		 if(k==0)
			 new->next = head, head = new; /*新结点插入到首结点前*/
	 	 else
		 {  p=head,j=0;
			while(p->next!=0 && j<k-1)     /*查找单链表的第i个结点*/
	    	   p=p->next,  j++  ;
		       /*在第k个结点或链表最后一个结点后插入新结点*/
	    	 new->next = p->next, p->next = new;
          }
     return(head);
}

struct link *delete(struct link  *head, int k)
{
	struct link *p,*q;
    int n = 0;
    if(k == 0)            /*删除第一个节结点 */
    {
		q = head;
	    head = head->next;
	    free(q);
    	return head;
      }
    p=head;
    while(p != 0 && n < k-1)
    	p=p->next ,n++;
    if(p == 0 )
{	printf("no this position\n");
		return head;
     }
      q = p->next;
      p->next = q->next;
      free( q) ;
      return head;
}
struct link  *find(struct link *head,int i)
{
	int j;
    struct link * p;
    p=head;j=0;
    while(p && j<i)
    {
	 	p=p->next;
		j++;
	}
	if (i==j)
		return p;
   else
	  return 0;
   }
struct link  * locate(struct link *head,int key)
{
    struct link * p=head;
    while( p!=0 && p->data!=key)
		p=p->next;
    if(p!=0)
      return p;
    else
      return 0;
}
void output (struct link *head)
{
	struct link *p=head;
	while(p!=0)
  	{
		if (p->next!=0)
		printf("%d ->",p->data);
		else
		printf ("%d\n",p->data);
  		p=p->next;
	}
}

/*#include "stdio.h"
#include"link.h"
#include"linkop.c"*/
void main()
{
	struct link *head,*p;
	 int x,i,j;
	 clrscr();
	 printf("create a linklist  input -1 to end\n");  /*以-1结束*/
	 head=create();
	 output(head);   /*输出创建的链表*/
	 printf("insert a node  in linklist \ninput x,i:");
	 scanf("%d%d",&x,&i);
	 head=insert(head,x,i);
	 output(head);    /*输出插入结点后的链表*/
	 printf("del a node in linklist\n input position i:");
	 scanf("%d",&i);
	 head=delete(head,i);
  	 output(head);    /*输出删除结点后的链表*/
	 printf("find node in linklist\n input i:");
	 scanf("%d",&i);
	 p=find(head,i);
	 if(p)
		printf("find node %d 's data:%d\n",i,p->data);
	 else
    		printf(" not find\n");
	printf("loacate node in linklist\n input x:");
	scanf("%d",&x);
	p=locate(head,x);
	if(p!=0)
		printf("locate the node's data:%d\n",p->data);
	else
		printf(" not find\n");
}





