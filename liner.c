#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10	//定义数组最大长度
#define ElementType int 


/*创建空的链表，插入值，查找值，删除值*/

/*定义链表指针和链表结构->数组类型存储*/
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};
/*声明函数*/
List MakeEmpty();
/*插入元素->在第i个位置插入X-备注第i个位置对应的数组的下标是i-1*/
void Insert(ElementType X, int i, List PtrL);

/*查找元素，返回元素所在的位置*/
int Find(ElementType X, List PtrL);

/*删除列表元素*/
void Delete(ElementType X, List PtrL); 


void main(){
	/*创建一个空结点*/
	List p = MakeEmpty();
	printf("The value of Last is %d\n",p->Last);
	Insert(56, 1,p);
	printf("the value of Last is %d\n",p->Last);
	printf("The value is %d\n", p->Data[0]);
	
	Insert(89, 2,p);
	Insert(65, 3,p);
	Insert(78, 4,p);
	Insert(99, 5,p);
	printf("the value of Last is %d\n",p->Last);
	printf("The value is %d\n", p->Data[0]);
	printf("The value is %d\n", p->Data[1]);
	int a = Find(78, p);
	printf("找到的值位置 is %d\n", a);
	
	return;
}

List MakeEmpty()
{
	List PtrL;
	//PtrL = (List)malloc(sizeof(List));
	PtrL = (List)malloc(sizeof(List));
	PtrL->Last = -1;
	return PtrL;	
} 

void Insert(ElementType X, int i, List PtrL)
{
	int j;
	/*判断表是否满了*/
	if(PtrL->Last == MAXSIZE - 1)
		printf("表满！");
	
	/*先判断插入的位置如果超出了边界则直接退出*/
	if(i < 1 || i > PtrL->Last + 2){
		printf("位置超出！");
		return;
	} 
	/*开始插入数据->先将i以后的数据后移，移动指针*/
	for(j = PtrL->Last;j >=i-1;j--){
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = X;
	PtrL->Last++;			/*Last仍然指向最大的元素位置*/
	return;	
}

int Find(ElementType X, List PtrL)
{
	int i;
	if(X == PtrL->Data[0])
		return 0;
	if(X == PtrL->Data[PtrL->Last])
		return PtrL->Last;
	/*在循环中判断i值与结点的Last值 并且X不等于Data[i]的值*/
	while(i < PtrL->Last && X != PtrL->Data[i])
		i++;
	/*判断如果i>PtrL->Last那么就超界限了，找不到直接退出*/
	if(i > PtrL->Last){
		printf("搜索完毕，目标值不存在!");
		return -1;
	} else{
		return i;
	}	
}

/*删除根据位置删除，2，根据元素删除*/
void Delete(int i, List PtrL)
{
	int j;
	/*先判断删除的位置的合法性*/
	if(i < 1 || i >PtrL->Last+1 ){
		printf("不存在第%d个元素",i);
		return;
	} 
	for(j = i; j <=PtrL->Last;j++){
		PtrL->Data[j-1] = PtrL->Data[j];
	}
	PtrL->Last--;
	return;
}


















