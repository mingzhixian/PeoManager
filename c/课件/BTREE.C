#include<stdio.h>
#include<stdlib.h>
#define NULL 0
typedef struct node{
       char data;
       struct node *lchild,*rchild;
    }TREENODE,BiTree;
TREENODE *root;
TREENODE *creat_tree( BiTree *);
void inorder(TREENODE *);
void inorder(TREENODE *p)
   {
       if(p!=NULL)
         {
            inorder(p->lchild);
             printf("%c  ",p->data);
         inorder(p->rchild);
        
	   }
 }
 countleaf(TREENODE *p)
 {  
    if(!p)
	   return 0;
    else 
	   if(p->lchild==NULL &&p->rchild==NULL ) 
		   return 1;
       else 
		  return countleaf(p->lchild)+countleaf(p->rchild);
        


 }
 int count=0;
  cl(TREENODE *p)
   {   if(p==NULL) return 0;
	   else
	     if(p->lchild==NULL &&p->rchild==NULL ) 
		   count++;
         else 
		 {  cl(p->lchild);
            cl(p->rchild);
		 }
	//return count;
 }

 TREENODE *CreateBiTree(BiTree *T)
 {   char ch;
     scanf("%c",&ch);
    if(ch==' ') T=0;
    else
    {
       T=(BiTree *)malloc(sizeof(BiTree));
       T->data=ch;
       T->lchild=CreateBiTree(T->lchild);
       T->rchild=CreateBiTree(T->rchild);
      }
  return T;
   }

main()
{BiTree *T;
T= CreateBiTree(T);
inorder(T);
{int n;
//n=countleaf(T);
cl(T);
printf("\ncount=%d\n",count);
}
}