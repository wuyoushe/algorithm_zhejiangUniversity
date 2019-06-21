#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode{
    ElementType data;				//���Ԫ��
    struct BiTNode* lchild;		    //����ָ��
    struct BiTNode* rchild;		    //�Һ���ָ��
}BitNode;							//���������
typedef BitNode * BiTree;			//ָ�����������ָ��

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
    printf("���������д���������...\n");
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
         /*�ж�n�Ƿ���ڵ�ǰ�Ĳ㼶level,���������ôlevel���±���ֵ*/
       if(n> *level){
           *level = n;
       }
       /*�ݹ�ı���������������*/
       getDepth(T->lchild, n+1, level);
       getDepth(T->rchild,n+1, level);
     }
 }




