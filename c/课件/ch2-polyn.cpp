#include"stdio.h"
#include"stdlib.h"
typedef struct list{
int data;
int expn;
struct list *next;
}List;

List *create1(int a[])
{List *h,*p,*s;
int x,e;
int i=0;
h=(List*)malloc(sizeof(List));
h->next =0;
s=h;
//scanf("%d%d",&x,&e);
x=a[i],e=a[i+1];
while(x)
{p=(List*)malloc(sizeof(List));
  p->data=x;
  p->expn=e;
  p->next =0;
  s->next=p;
  s=p;
	 // scanf("%d%d",&x,&e);
  i+=2;
  x=a[i],e=a[i+1];
}
return h;
}
disp(List *h)
{List *p=h;
 while(p)
	{ printf("(%d,%d)->  ",p->data,p->expn );
     p=p->next;
 }
 printf("\n");
}

addpolyn(List *h1,List*h2)
{List *h,*pa,*pb,*pc;
 h=h1;
 pa=h1->next ;
 pb=h2->next ;
 while(pa&&pb)
 { // disp(h1->next); 
	if(pa->expn !=pb->expn)
	   if(pa->expn<pb->expn)  
	   {h->next =pa;
        h=pa;
        pa=pa->next;
	   }
	   else{
		   h->next =pb;
           h=pb;
           pb=pb->next;
	   }
     else
		 if(pa->data+pb->data==0){
		  pc=pa;
	      pa=pa->next;
	      free(pc);
          pc=pb;
	      pb=pb->next;
	      free(pc);}
		 else
		 {
			 pa->data+=pb->data;
	         h->next=pa;
		     h=pa;
		     pa=pa->next;
             
			 pc=pb;
	         pb=pb->next;
	         free(pc);
		 }
 
 }

 if(pa)
 h->next=pa;
 else
  h->next=pb;

}
 main()
{int a[]={7,0,3,1,9,8,7,9,5,17,0,0};
 int b[]={8,1,22,7,-9,8,5,9,0,0};
 List *h1,*h2;
 h1=create1(a);
 disp(h1->next);
 h2=create1(b);
 disp(h2->next);
 addpolyn(h1,h2);
 disp(h1->next);
 
}