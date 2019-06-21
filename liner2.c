#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define NUll -1
/*�����ṹָ��*/
typedef struct LNode *List;
struct LNode{
	ElementType Data;	/*�洢�������*/
	List Next;			/*�洢ָ����һ������ָ��*/
};

/*�������Һ�����һ���ǰ�����Ų���һ���ǰ���ֵ����*/
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

/*�ڶ��е�i��λ�ò���Ԫ��X*/
List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if(i == 1){
		s = (List)malloc(sizeof(List));	/*����ͷ���*/
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i-1, PtrL);
	if(p == NULL){
		printf("��������!");
		return NULL;
	}else{
		s = (List)malloc(sizeof(List));
		s->Data = X;
		s->Next = p->Next;	/*�½����뵽��i-1�����ĺ���*/
		p->Next = s;
		return PtrL;
	}
	
}
/*1�����ҵ�����ĵ�i-1����� 2�� ����ָ��sָ��Ҫ��ɾ���Ľ�� p->Next
  3,Ȼ���޸�ָ�룬ɾ��s��ָ�Ľ��
  4������ͷ�s��ָ���Ŀռ� 
*/ 
List Delete(int i, List PtrL)
{
	List p,s;
	if(i ==1){	//��Ҫɾ�����Ǳ�ĵ�һ����� 
		s = PtrL;							/*sָ���һ�����*/
		if(PtrL != NULL) PtrL = PtrL->Next;	/*��������ɾ��*/
		else return NULL;
		free(s);
		return PtrL; 
	}
	p = FindKth(i-1, PtrL);					/*����Ҫ�������ǰ��һ�����*/
	if(p == NULL){
		printf("��%d����㲻����", i-1);	return NULL;
	}else if(p->Next == NULL){
		printf("��%d����㲻����",i);		return NULL;
	}else{
		s = p->Next;			/*sָ���i�����*/
		p->Next = s->Next;		/*��i����������ӵ�i-1��λ���ϣ���������ɾ��*/
		free(s);				/*�ͷű�ɾ�����*/
		return PtrL; 
		
	}	
}

























 





