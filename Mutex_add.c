#include <stdio.h>
/*1������洢����ʽ�����ݽṹ*/
typedef struct PolyNode *Polynomial;

struct PolyNode {
	int coef;				//ϵ��
	int expon;				//ָ��
	struct PolyNode *link; 	//ָ����һ���ڵ��ָ�� 
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
