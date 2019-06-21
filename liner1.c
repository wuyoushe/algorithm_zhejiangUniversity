/*�������ж���һ������ 
1������һ����ջ
2�����������Ԫ��
3������Ԫ��
4��ɾ��Ԫ�� 
*/

#include <stdio.h>
#define MAXSIZE 10
#define ElementType int

/*����һ���ṹ��*/
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int last;
}; 

/*���ؽṹ��*/
List makeEmpty();

/*����λ�ò���Ԫ��*/
void Insert(ElementType x, int i, List PtrL);

main()
{
	/*����һ���յĿռ�*/
}

List makeEmpty()
{
	List PtrL;
	//PtrL = (List)malloc(sizeof(struct LNode));
	PtrL = (List)malloc(sizeof(List));
	PtrL->last = -1;
	return PtrL;
}

/*��ɲ���,��λ�ò���Ԫ��*/
void Insert(ElementType x, int i, List PtrL)
{
	int j;
	//�жϲ����λ�� 
	if(PtrL->last == MAXSIZE - 1){
		printf("������");
		return;
	}
	if(i < 1 || i > MAXSIZE + 2){
		printf("λ�ò��Ϸ�");
		return;
	}
	/*���������в�����i�����Ԫ�����κ��ƣ�Ȼ��Ԫ�ز�����i-1��λ��*/
	for(j = PtrL->last;j>=i-1;j--){
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = x;
	PtrL->last++;
	return;
}

void Delete(int i, List PtrL)
{
	int j;
	if(i < 1 || i > PtrL->last+1) {
		printf("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for(j = i; j <= PtrL->last;j++){
		PtrL->Data[j-1] = PtrL->Data[j];
		PtrL->last--;
		return;
	}
}

int Find(ElementType x, List PtrL)
{
	int i = 0;
	while(i <= PtrL->last && PtrL->Data[i]!= x)
		i++;
	if(i > PtrL->last) return -1;
	else return i;
}
