#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define NUll -1
/*声明结构指针*/
typedef struct LNode *List;
struct LNode{
	ElementType Data;	/*存储结点数据*/
	List Next;			/*存储指向下一个结点的指针*/
};

/*声明查找函数，一种是按照序号查找一种是按照值查找*/
List MakeEmpty();

List FindKth(int K, List PtrL);

List Find(ElementType X, List PtrL);

List Insert(ElementType X, int i, List PtrL);

void Delete(int i, List PtrL);

void main()
{
	List p = MakeEmpty();
	int X = 56;
	int i = 1;
	List m =  Insert(X, i, p);
	List n =  Insert(X, i, p);
	printf("The value is %d\n", m->Data);
	printf("The value is %d\n", n->Data);
	
	
}

List MakeEmpty()
{
	List PtrL;
	//PtrL = (List)malloc(sizeof(List));
	PtrL = (List)malloc(sizeof(List));
	PtrL->Next = NUll;
	return PtrL;	
} 

List FindKth(int K, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while(p != NULL && i < K){
		p = p->Next;
		i++;
	}
	if(i == K) return p;
	else return 0;
}

List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while(p != NULL && p->Data != X)
		p = p->Next;
	return p;
}

/*在队列的i的位置插入元素X*/
List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if(i == 1){
		s = (List)malloc(sizeof(List));	/*申请头结点*/
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i-1, PtrL);
	if(p == NULL){
		printf("参数错误!");
		return NULL;
	}else{
		s = (List)malloc(sizeof(List));
		s->Data = X;
		s->Next = p->Next;	/*新结点插入到第i-1个结点的后面*/
		p->Next = s;
		return PtrL;
	}
	
}
/*1，先找到链表的第i-1个结点 2， 再用指针s指向要被删除的结点 p->Next
  3,然后修改指针，删除s所指的结点
  4，最后释放s所指结点的空间 
*/ 
List Delete(int i, List PtrL)
{
	List p,s;
	if(i ==1){	//若要删除的是表的第一个结点 
		s = PtrL;							/*s指向第一个结点*/
		if(PtrL != NULL) PtrL = PtrL->Next;	/*从链表中删除*/
		else return NULL;
		free(s);
		return PtrL; 
	}
	p = FindKth(i-1, PtrL);					/*查找要插入结点的前面一个结点*/
	if(p == NULL){
		printf("第%d个结点不存在", i-1);	return NULL;
	}else if(p->Next == NULL){
		printf("第%d个结点不存在",i);		return NULL;
	}else{
		s = p->Next;			/*s指向第i个结点*/
		p->Next = s->Next;		/*将i结点后面的链接到i-1的位置上，从链表中删除*/
		free(s);				/*释放被删除结点*/
		return PtrL; 
		
	}	
}

























 





