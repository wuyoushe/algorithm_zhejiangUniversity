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

void Delete(int i, List PtrL);					//删除操作 

void main() {
	List list = MakeEmpty();
	Insert(1, 1, list);
	Insert(3, 2, list);
	Insert(4, 3, list);
	Insert(5, 4, list);
	
	int position = Find(4, list);
	printf("The value of position is %d", position);
	
	
}

/*建立空的顺序表*/
List MakeEmpty() {
	List PtrL;
	/*申请空间*/
	PtrL = (List)malloc(sizeof(List));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X, List PtrL){
	int i = 0;
	while( i <= PtrL->Last && PtrL->Data[i] != X)
		i++;
	if(i > PtrL->Last) return -1;	/*如果没有找到返回-1*/
	else return i;
}

void Insert(ElementType X, int i, List PtrL){
	int j;
	/*表空间满，不能插入*/
	if(PtrL->Last == MAXSIZE - 1) {
		printf("表满，不能插入");
		return; 
	}
	if(i < 1 || i > PtrL->Last+2){
		printf("位置不合理");
		return;
	}
	/*将ai~an倒序向后移动*/
	for(j = PtrL->Last;j > i - 1; j--) {
		PtrL->Data[j+1] = PtrL->Data[j]; 
	}
	PtrL->Data[i-1] = X;					/*新元素插入*/
	PtrL->Last ++;	
	return;						/*Last仍然指向租后元素*/
}

void Delete(int i, List PtrL){
	int j;
	if(i < 1 || i > PtrL->Last+1) {
	printf("不存在第%d个元素", i);
	return;
	}
	
	for(j = i; j <= PtrL->Last; j++){
		PtrL->Data[j-1] = PtrL->Data[j];
	} 
	PtrL->Last--;
	return;
} 




















