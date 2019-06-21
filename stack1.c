#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define ERROR 0

typedef struct SNode *Stack;
typedef int ElementType;

struct SNode{
	ElementType Data[MaxSize];	/*用一个数组来表示栈*/
	int Top;					/*表示栈顶的位置*/
};

void Push(Stack Ptrs, ElementType item);
ElementType Pop(Stack PtrS);
Stack CreateStack();

void main()
{
	Stack S = CreateStack();
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	int X1 = Pop(S);
	int X2 = Pop(S);
	int X3 = Pop(S);
	int X4 = Pop(S);
	int X5 = Pop(S);
	printf("The value of pop is %d\n", X1);
	printf("The value of pop is %d\n", X2);
	printf("The value of pop is %d\n", X3);
	printf("The value of pop is %d\n", X4);
	printf("The value of pop is %d\n", X5);
}

/*初始化堆栈空间*/
Stack CreateStack()
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;
	return S;
}

void Push(Stack PtrS, ElementType item)
{
	//判断堆栈满了没
	if(PtrS->Top == MaxSize - 1){
		printf("堆栈满");return;
	} else{
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}	
}

ElementType Pop(Stack PtrS)
{
	if(PtrS->Top == -1){
		printf("堆栈空");
		return ERROR;
	}else{
		return (PtrS->Data[(PtrS->Top)--]);
	}
}
