#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Bubble(ElementType Array[],int N);
void Swap(int *ar1, int *ar2);

void main()
{
	int k;
	ElementType a[] = {3,2,5,7,12,9,8};
	int len = sizeof(a) /sizeof(a[0]);
	Bubble(a,len);
	//printf("���鳤��Ϊ%d\n",sizeof(a)/sizeof(a[0]));
	for(k = 0; k < len; k++){
		printf("������Ԫ����%d\n", a[k]);
	}	
}

//�������飬������������� 
void Bubble(ElementType Array[],int N)
{
	int i,j;
	//printf("N--%d\n", N);
	//��ȡ����ĳ��ȣ�ȷ�������Ĵ���
	for(i = 0; i < N ; i++){
		//printf("i-1-%d\n", i);
		for(j = 0; j < N-i-1;j++){
			//printf("j-1-%d\n", j);
			if(Array[j] > Array[j+1]){
				//printf("j-2-%d\n", j);
				Swap(&Array[j], &Array[j+1]);
			}
		}
	} 
	
}

void Swap(int *ar1, int *ar2){
	int temp;
	temp = *ar1;
	*ar1 = *ar2;
	*ar2 = temp;
}
