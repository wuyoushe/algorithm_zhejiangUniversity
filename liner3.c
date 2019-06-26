#include <stdio.h>

void main() {
	/*以数组的下标表示元素的幂次，数组的元素表示前面的系数*/
	int array[10];
	array[0] = 1;
	array[2] = -3;
	array[5] = 4;
	int len = sizeof(array) / sizeof(int);
	printf("The lenght of len is %d", len);
	for(int i = 0; i < len; i++) {
		if(array[i] != 0) {
			
		}
	}
	
	
}
