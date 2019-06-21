#include<stdio.h>

void Insert_Sort(int array[], int N);

void main()
{
	int array[] = {3,2,5,7,12,9,8};
	int i;
	int N = sizeof(array) / sizeof(array[0]);
	
	Insert_Sort(array, N);
	
	//打印出排序好的数组
	for(i = 0; i < N; i++) {
		printf("The value is %d\n", array[i]);
	} 
}

void Insert_Sort(int array[], int N){
	int p,i,Tmp;
	for(p = 1; p < N; p++){
		Tmp = array[p];		//摸下一张牌
		for(i = p; i >0 && array[i-1]>Tmp; i--){
			array[i] = array[i-1];
		}	
		array[i] = Tmp;
	}
}
