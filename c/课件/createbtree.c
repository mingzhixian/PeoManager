#include"stdio.h"
#include"stdlib.h"
typedef struct bt{
int data;
struct bt *l,*r;
}btree;

btree *create()
{btree *t,*p,*q[20];
 int r=0,f=0,x;
 scanf("%d",&x);
 if(x)
	{ t=(btree *)malloc(sizeof(btree));
 t->data=x;
 q[r]=t;
 r++;}
 while(f<r)
	{p=q[f];f++;
     printf("ÊäÈë %d lchild:",p->data);
     scanf("%d",&x);
     if(x==0)
	  p->l=0;
	 else
	 {p->l=(btree *)malloc(sizeof(btree));
	   p->l->data=x;
	   q[r]=p->l;
	   r++;
	 }
	 printf("ÊäÈë %d rchild:",p->data);
     scanf("%d",&x);
     if(x==0)
	  p->r=0;
	 else
	 {p->r=(btree *)malloc(sizeof(btree));
	   p->r->data=x;
	   q[r]=p->r;
	   r++;
	 }
	}

 return t;
}
preorder(btree *t)
{if(t)
{ printf("%d  ",t->data);
 preorder(t->l);
 preorder(t->r);
}
}
inorder(btree *t)
{if(t)
{ inorder(t->l);
  printf("%d  ",t->data);
  inorder(t->r);
}
}

main()
{btree *t;
 t=create();
 preorder(t);
 printf("\n");
 inorder(t);
}