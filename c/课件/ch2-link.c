#include"stdio.h"
#include"stdlib.h"
typedef struct list{
int data;
struct list *next;
}List;

List *create()
{List *h,*p;
int x;
h=0;
scanf("%d",&x);
while(x)
{p=(List*)malloc(sizeof(List));
  p->data=x;
  p->next =h;
  h=p;
	  scanf("%d",&x);
}
return h;
}

List *create1()
{List *h,*p,*s;
int x;
h=(List*)malloc(sizeof(List));
h->next =0;
s=h;
scanf("%d",&x);
while(x)
{p=(List*)malloc(sizeof(List));
  p->data=x;
  p->next =0;
  s->next=p;
  s=p;
	  scanf("%d",&x);
}
return h;
}
insert(List *h,int i,int e)
{List *p,*s;
 int l=1;
 p=h;
 while(p&&l<i)
 {p=p->next;
 l++;}
  if(p)
  {s=(List*)malloc(sizeof(List));
   s->data=e;
   s->next =p->next ;
   p->next =s;
  } 
}
del(List *h,int i)
{List *p,*s;
 int l=1;
 p=h;
 
 
 while(p&&l<i)
 {p=p->next;
  l++;}
  if(p)
  {
	  s=p->next;
	  p->next =p->next->next;
      free(s); 
  } 
}

disp(List *h)
{List *p=h;
 while(p)
	{ printf("%d  ",p->data);
     p=p->next;
 }
 printf("\n");
}
List *find(List h,int i)
{int k=0;
 List *p=&h;
 while(p&&k<i)
	{  p=p->next;
      k++;
 }
  if(p)
	  return p;
  else 
	  return 0;
}
find1(List h,int e)
{int k=0;
 List *p=&h;
 while(p)
	{if(p->data==e)
	  break;
	  p=p->next;
      k++;
 }
 if(p)
   return k;  
 else
   return 0;
}


main()
{List *h,*p;
 h=create();
 disp(h->next);
 insert(h,3,100);
 disp(h->next);
 insert(h,7,1000);
 disp(h->next);
 del(h,4);
 disp(h->next);
 p=find(*h,7);
 if(p)
   printf("%d\n",p->data);
 else
   printf("not found!\n");
printf("%d\n",find1(*h,10));
}