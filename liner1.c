/*创建队列定义一个队列 
1，创建一个空栈
2，往队列添加元素
3，查找元素
4，删除元素 
*/

#include <stdio.h>
#define MAXSIZE 10
#define ElementType int

/*定义一个结构体*/
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int last;
}; 

/*返回结构体*/
List makeEmpty();

/*按照位置插入元素*/
void Insert(ElementType x, int i, List PtrL);

main()
{
	/*创建一个空的空间*/
}

List makeEmpty()
{
	List PtrL;
	//PtrL = (List)malloc(sizeof(struct LNode));
	PtrL = (List)malloc(sizeof(List));
	PtrL->last = -1;
	return PtrL;
}

/*完成插入,按位置插入元素*/
void Insert(ElementType x, int i, List PtrL)
{
	int j;
	//判断插入的位置 
	if(PtrL->last == MAXSIZE - 1){
		printf("表已满");
		return;
	}
	if(i < 1 || i > MAXSIZE + 2){
		printf("位置不合法");
		return;
	}
	/*插入链表中操作将i后面的元素依次后移，然后将元素插入在i-1的位置*/
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
		printf("不存在第%d个元素", i);
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
