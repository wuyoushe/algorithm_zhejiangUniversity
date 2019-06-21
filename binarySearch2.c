#include <stdio.h>

#define NotFound -1
#define ElementType int

/*������ֲ��Һ�������������õ������Ŀ��ֵ�����ҳ�Ŀ��ֵ���±�*/
ElementType BinarySearch(int a[], int Data, int length);

void main(){
	int a[] = {1, 15, 18, 28, 32, 98, 106, 128,159};
	int length = sizeof(a) / sizeof(int);
	int w = BinarySearch(a, 1, length);
	int n = BinarySearch(a, 32, length);
	int m = BinarySearch(a, 65, length);
	printf("The find position is %d\n", w);
	printf("The find position is %d\n", n);
	printf("The find position is %d\n", m);
	
}

ElementType BinarySearch(int a[], int Data, int length){
	/*���ֲ���ȷ�����˺��м�ֵ�������ȣ���ô���ӶȾ͵���O(1),�Ƚ�Ŀ��ֵ���м�ֵ*/
	int head = 0;
	int mid;
	
	if(Data == a[head]) return head;
	else if(Data == a[length]) return length;
	
	while(head <= length){
		mid = (head + length)/2;
		if(Data < a[mid]) length = mid - 1;
		else if(Data > a[mid]) head	 = mid + 1;
		else return mid;
	}
	return NotFound;
}
