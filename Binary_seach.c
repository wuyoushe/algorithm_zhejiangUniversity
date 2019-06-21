#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode{
    ElementType data;				//结点元素
    struct BiTNode* lchild;		    //左孩子指针
    struct BiTNode* rchild;		    //右孩子指针
}BitNode;							//二叉树结点
typedef BitNode * BiTree;			//指向二叉树结点的指针

struct Node{
	ElementType Data;
	struct Node * Next;
};

struct QNode{
	struct Node * rear;
	struct Node * front;
};
typedef struct QNode *Queue;
Queue PtrQ;


void CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);

int getBitreeDepth(BiTree T);
void getDepth(BiTree T, int n, int *level);

 void main(void){
    BiTree T;
    printf("按先序序列创建二叉树...\n");
    CreateBiTree(&T);
    PreOrderTraverse(T);
     printf("\n");
    InOrderTraverse(T);
     printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("\nthe depth of the binary tree is %d\n", getBitreeDepth(T));

}

void CreateBiTree(BiTree *T){

    char ch;
    scanf("%c", &ch);
    if(ch == '#')
        *T = NULL;
    else{
        *T = (BiTree)malloc(sizeof(BitNode));
        if(!*T){
            exit(-1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void PreOrderTraverse(BiTree T)
{
    if(T){
        printf("%3c", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        printf("%3c", T->data);
        PreOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        printf("%3c", T->data);
    }
}

int getBitreeDepth(BiTree T){
     int level = 0;
     int n = 1;
     getDepth(T, n, &level);
     return level;
 }

 void getDepth(BiTree T, int n, int *level){
     if(T != NULL){
         /*判断n是否大于当前的层级level,如果大于那么level重新被赋值*/
       if(n> *level){
           *level = n;
       }
       /*递归的遍历树的左右子树*/
       getDepth(T->lchild, n+1, level);
       getDepth(T->rchild,n+1, level);
     }
 }




