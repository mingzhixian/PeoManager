#include"stdio.h" 
#include"stdlib.h" 

typedef struct BSTNode{
   int key;    //Êý¾ÝÓò
 struct  BSTNode *lchild,*rchild;
}BSTNode;

int InsertBST(BSTNode **p, int k)
  {
     if(*p==NULL)
     {
       (*p)=(BSTNode*)malloc(sizeof(BSTNode));
       (*p)->key=k;
       (*p)->lchild=(*p)->rchild=NULL;
       return 0;
     }
     else if(k==(*p)->key)
       return 0;
     else if(k<(*p)->key)
       InsertBST(p->lchild, k);
     else
       InsertBST(p->rchild, k);
  }
 BSTNode *CreateBST(int A[], int n)
  {
    BSTNode *bt=NULL;
    int i=0;
    while(i<n)
    {
     bt=InsertBST(bt, A[i]);
      i++;
    }
    return bt;
  }
 inorder(BSTNode *T)
 {if(T)
 { inorder(T->lchild);
   printf("%d ",T->key);
   inorder(T->rchild);
 }
 }
 main()
 {int  a[]={50,16,56,52,8};
  BSTNode *bt;
  bt=CreateBST(a,5);
  inorder(bt);
 }
