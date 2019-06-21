#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;	//这里用int 作为树结点的数据
 
typedef struct BiTNode
{
	ElemType data;
	struct  BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode, *BiTree;
 
void createBiTree(BiTree *T);		//创建树
void preOrderTraverse(BiTree T);	//前序遍历
void inOrderTraverse(BiTree T);		//中序遍历
void postOrderTraverse(BiTree T);	//后序遍历
 
int main()
{
	BiTree T = NULL;
	createBiTree(&T);
	preOrderTraverse(T);
	printf("\n");
	inOrderTraverse(T);
	printf("\n");
	postOrderTraverse(T);
	return 0;
}
 
void createBiTree(BiTree *T)
{
	ElemType ch;
	scanf ("%d", &ch);	//如果是字符型 %c 回车输入算一个字符，ubutun会一直递归 
	if (0 == ch)//扩展二叉树，虚结点 == 0
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	//!!! stdlib.h 头文件一定要加！！！
		if (!*T)
		{
			exit(1);	//错误退出
		}
		(*T)->data = ch;	//生成根结点
		createBiTree(&((*T)->lchild));	//构造左子树
		createBiTree(&((*T)->rchild));	//构造右子树
	}
}
 
void preOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	printf("%d", T->data);	//显示结点数据，可以改成其他对结点的操作
	preOrderTraverse(T->lchild);	//再先序遍历左子树
	preOrderTraverse(T->rchild);	//最后先序遍历右子树
}
 
void inOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	inOrderTraverse(T->lchild);	//中序遍历左子树
	printf("%d", T->data);			//显示结点数据，可以改成其他对结点的操作
	inOrderTraverse(T->rchild);	//最后再中序遍历右子树
}
 
void postOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	postOrderTraverse(T->lchild);	//先后序遍历左子树
	postOrderTraverse(T->rchild);	//再后序遍历右子树
	printf("%d", T->data);			//显示结点数据，可以改成其他对结点的操作
}
