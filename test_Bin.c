#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;	//������int ��Ϊ����������
 
typedef struct BiTNode
{
	ElemType data;
	struct  BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode, *BiTree;
 
void createBiTree(BiTree *T);		//������
void preOrderTraverse(BiTree T);	//ǰ�����
void inOrderTraverse(BiTree T);		//�������
void postOrderTraverse(BiTree T);	//�������
 
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
	scanf ("%d", &ch);	//������ַ��� %c �س�������һ���ַ���ubutun��һֱ�ݹ� 
	if (0 == ch)//��չ������������ == 0
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	//!!! stdlib.h ͷ�ļ�һ��Ҫ�ӣ�����
		if (!*T)
		{
			exit(1);	//�����˳�
		}
		(*T)->data = ch;	//���ɸ����
		createBiTree(&((*T)->lchild));	//����������
		createBiTree(&((*T)->rchild));	//����������
	}
}
 
void preOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	printf("%d", T->data);	//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
	preOrderTraverse(T->lchild);	//���������������
	preOrderTraverse(T->rchild);	//����������������
}
 
void inOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	inOrderTraverse(T->lchild);	//�������������
	printf("%d", T->data);			//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
	inOrderTraverse(T->rchild);	//������������������
}
 
void postOrderTraverse(BiTree T)
{
	if (NULL == T)
	{
		return;
	}
	postOrderTraverse(T->lchild);	//�Ⱥ������������
	postOrderTraverse(T->rchild);	//�ٺ������������
	printf("%d", T->data);			//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
}
