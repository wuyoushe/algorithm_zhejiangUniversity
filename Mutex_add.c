#include <stdio.h>
/*1，定义存储二项式的数据结构*/
typedef struct PolyNode *Polynomial;

struct PolyNode {
	int coef;				//系数
	int expon;				//指数
	struct PolyNode *link; 	//指向下一个节点的指针 
};

Polynomial ReadPoly();
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2);
void PrintPoly(PrintPoly P);
void Attach(int c, int e, Polynomial *pRear);

int main() {
	Polynomial P1,P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	
	pp = Mult(P1, P2);
	PrintPoly(PP);
	
	PS = Add(P1, P2);
	PrintPoly(PS);
	
	return 0; 
} 

Polynomial ReadPoly() {
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	
	return P
}

void Attach(int c, int e, Polynomial *pRear){
	
}
