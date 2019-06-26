#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXSIZE 10

typedef int ElementType ;

typedef struct LNode * List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};

List MakeEmpty();

int Find(ElementType X, List PtrL);

void Insert(ElementType x, int i, List ListPtrL);

void Delete(int i, List PtrL);					//ɾ������ 

void main() {
	List list = MakeEmpty();
	Insert(1, 1, list);
	Insert(3, 2, list);
	Insert(4, 3, list);
	Insert(5, 4, list);
	
	int position = Find(4, list);
	printf("The value of position is %d", position);
	
	
}

/*�����յ�˳���*/
List MakeEmpty() {
	List PtrL;
	/*����ռ�*/
	PtrL = (List)malloc(sizeof(List));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X, List PtrL){
	int i = 0;
	while( i <= PtrL->Last && PtrL->Data[i] != X)
		i++;
	if(i > PtrL->Last) return -1;	/*���û���ҵ�����-1*/
	else return i;
}

void Insert(ElementType X, int i, List PtrL){
	int j;
	/*��ռ��������ܲ���*/
	if(PtrL->Last == MAXSIZE - 1) {
		printf("���������ܲ���");
		return; 
	}
	if(i < 1 || i > PtrL->Last+2){
		printf("λ�ò�����");
		return;
	}
	/*��ai~an��������ƶ�*/
	for(j = PtrL->Last;j > i - 1; j--) {
		PtrL->Data[j+1] = PtrL->Data[j]; 
	}
	PtrL->Data[i-1] = X;					/*��Ԫ�ز���*/
	PtrL->Last ++;	
	return;						/*Last��Ȼָ�����Ԫ��*/
}

void Delete(int i, List PtrL){
	int j;
	if(i < 1 || i > PtrL->Last+1) {
	printf("�����ڵ�%d��Ԫ��", i);
	return;
	}
	
	for(j = i; j <= PtrL->Last; j++){
		PtrL->Data[j-1] = PtrL->Data[j];
	} 
	PtrL->Last--;
	return;
} 




















