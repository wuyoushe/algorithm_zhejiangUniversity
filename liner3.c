#include <stdio.h>

void main() {
	/*��������±��ʾԪ�ص��ݴΣ������Ԫ�ر�ʾǰ���ϵ��*/
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
