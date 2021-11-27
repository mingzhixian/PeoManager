#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;
	struct node *next;
}Lnode;
show(Lnode *h)
{Lnode *p=h->next;
 while(p)
	{printf("%d ->",p->data);
    p=p->next;}
printf("\n");
}
Lnode *create()
{int x;
 Lnode *h,*p;
  h=0;
  printf("input -1 to end!\n");
  scanf("%d",&x);
 while(x!=-1)
 { p=(Lnode *)malloc(sizeof(Lnode));
   p->data=x;
   p->next=h;
   h=p;
   show(h);

   scanf("%d",&x);
 }
 p=(Lnode *)malloc(sizeof(Lnode));
 p->next=h;
 h=p;
   
 return h;
  
}

Lnode *create1()
{int x;
 Lnode *h,*p,*r;
 h=(Lnode *)malloc(sizeof(Lnode));
 h->next=0;
 r=h;

 ;
  printf("input -1 to end!\n");
  scanf("%d",&x);
 while(x!=-1)
 { p=(Lnode *)malloc(sizeof(Lnode));
   p->data=x;p->next=0;

   r->next=p;
   r=p;
   show(h);

   scanf("%d",&x);
 }
   
 return h;
  
}



main()
{Lnode *h;
 h=create1();
 show(h);
}

