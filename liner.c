#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10	//����������󳤶�
#define ElementType int 


/*�����յ���������ֵ������ֵ��ɾ��ֵ*/

/*��������ָ�������ṹ->�������ʹ洢*/
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};
/*��������*/
List MakeEmpty();
/*����Ԫ��->�ڵ�i��λ�ò���X-��ע��i��λ�ö�Ӧ��������±���i-1*/
void Insert(ElementType X, int i, List PtrL);

/*����Ԫ�أ�����Ԫ�����ڵ�λ��*/
int Find(ElementType X, List PtrL);

/*ɾ���б�Ԫ��*/
void Delete(ElementType X, List PtrL); 


void main(){
	/*����һ���ս��*/
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
	printf("�ҵ���ֵλ�� is %d\n", a);
	
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
	/*�жϱ��Ƿ�����*/
	if(PtrL->Last == MAXSIZE - 1)
		printf("������");
	
	/*���жϲ����λ����������˱߽���ֱ���˳�*/
	if(i < 1 || i > PtrL->Last + 2){
		printf("λ�ó�����");
		return;
	} 
	/*��ʼ��������->�Ƚ�i�Ժ�����ݺ��ƣ��ƶ�ָ��*/
	for(j = PtrL->Last;j >=i-1;j--){
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = X;
	PtrL->Last++;			/*Last��Ȼָ������Ԫ��λ��*/
	return;	
}

int Find(ElementType X, List PtrL)
{
	int i;
	if(X == PtrL->Data[0])
		return 0;
	if(X == PtrL->Data[PtrL->Last])
		return PtrL->Last;
	/*��ѭ�����ж�iֵ�����Lastֵ ����X������Data[i]��ֵ*/
	while(i < PtrL->Last && X != PtrL->Data[i])
		i++;
	/*�ж����i>PtrL->Last��ô�ͳ������ˣ��Ҳ���ֱ���˳�*/
	if(i > PtrL->Last){
		printf("������ϣ�Ŀ��ֵ������!");
		return -1;
	} else{
		return i;
	}	
}

/*ɾ������λ��ɾ����2������Ԫ��ɾ��*/
void Delete(int i, List PtrL)
{
	int j;
	/*���ж�ɾ����λ�õĺϷ���*/
	if(i < 1 || i >PtrL->Last+1 ){
		printf("�����ڵ�%d��Ԫ��",i);
		return;
	} 
	for(j = i; j <=PtrL->Last;j++){
		PtrL->Data[j-1] = PtrL->Data[j];
	}
	PtrL->Last--;
	return;
}


















