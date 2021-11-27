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
        printf("����%d�����ӽڵ㣺", ch);  
        CreateBiTree(&(*T)->lChild);  
        printf("����%d�����ӽڵ㣺", ch);  
        CreateBiTree(&(*T)->rChlid);  
    }  
  
    return 1;  
}  

void TraverseBiTree(BiTree T)  
{  
    if (NULL == T)  
       return ;  
    printf("%d ", T->data);  
    TraverseBiTree(T->lChild);  
    TraverseBiTree(T->rChlid);  
}  
SearchBST(BiTree T, int key, BiTree f, BiTree *p)  
{  
    if (!T)                     //δ�ҵ�  
    {  
        *p = f;  
        return 0;  
    }  
    else if (key == T->data) //���ҳɹ�  
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
/********************************************************/  
int main(void)  
{  
    BiTree T;  
    BiTree *p = (BiTree*)malloc(sizeof(BiTree));  
    int i=0;  
    CreateBiTree(&T);  
//  SearchBST(T, 98, NULL, p);  
    InsertBST(&T, 99);  
    TraverseBiTree(T);  
    return 0;  
}  