#include <stdio.h>

#define NotFound -1
#define ElementType int

/*定义二分查找函数，输入排序好的数组和目标值，查找出目标值的下标*/
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
	/*二分查找确定两端和中间值，如果相等，那么复杂度就等于O(1),比较目标值与中间值*/
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
