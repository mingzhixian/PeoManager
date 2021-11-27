#include <stdio.h>  
#include <stdlib.h>  
typedef struct BiTNode{  
    int    data;                  
    struct BiTNode  *lChild, *rChlid;  
}BiTNode, *BiTree;  
 CreateBiTree(BiTree *T)  
{  
    int ch,temp;  
    scanf("%d", &ch);  
    temp = getchar();  
    if ( ch==-1)  
        *T = NULL;  
    else  
    {  
        *T = (BiTree)malloc(sizeof(BiTNode));  
        if (!(*T))  
            exit(-1);  
  
        (*T)->data = ch;  
        printf("输入%d的左子节点：", ch);  
        CreateBiTree(&(*T)->lChild);  
        printf("输入%d的右子节点：", ch);  
        CreateBiTree(&(*T)->rChlid);  
    }  
  
    return 1;  
}  

void preTraverseBiTree(BiTree T)  
{  
    if (NULL == T)  
       return ;  
    printf("%d ", T->data);  
    preTraverseBiTree(T->lChild);  
    preTraverseBiTree(T->rChlid);  
} 
void inTraverseBiTree(BiTree T)  
{  
    if (NULL == T)  
       return ;  
    inTraverseBiTree(T->lChild);  
    printf("%d ", T->data);    
    inTraverseBiTree(T->rChlid);  
}  
SearchBST(BiTree T, int key, BiTree f, BiTree *p)  
{  
    if (!T)                     //未找到  
    {  
        *p = f;  
        return 0;  
    }  
    else if (key == T->data) //查找成功  
    {  
        *p = T;  
        return 1;  
    }  
    else if (key<T->data)  
        return SearchBST(T->lChild, key, T, p);  
    else  
        return SearchBST(T->rChlid, key, T, p);  
}  
int InsertBST(BiTree *T, int key)  
{  
    BiTree p, s;  
    if (!SearchBST(*T, key, NULL, &p))  
    {  
        s = (BiTree)malloc(sizeof(BiTNode));  
        s->data = key;  
        s->lChild = s->rChlid = NULL;  
  
        if (!p)  
            *T = s;  
        else if (key<p->data)  
            p->lChild = s;  
        else  
            p->rChlid = s;  
        return 1;  
    }  
    else  
        return 0;  
}  
int main(void)  
{  
    BiTree T;  
    BiTree *p = (BiTree*)malloc(sizeof(BiTree));  
    int i=0; 
	printf("create bitree:");
    CreateBiTree(&T);  
    SearchBST(T, 98, NULL, p);  
    InsertBST(&T, 99);  
    InsertBST(&T, 9);  
    InsertBST(&T, 90);  
    InsertBST(&T, 19);  
  printf("\n pre \n") ;   
 preTraverseBiTree(T);  
  printf("\n inordor \n") ;
 inTraverseBiTree(T);  

    return 0;  
}  