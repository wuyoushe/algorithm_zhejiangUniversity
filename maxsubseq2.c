#include <stdio.h>

int N, num[100005];

int maxSubSequence(int A[], int N); 


int main()
{	
	scanf("%d", &N);
	/*��ȡ�������������������������100000*/
	int i, j;
	for(i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	} 
	
	int sum = maxSubSequence(num, N);
	printf("The max subseq is %d\n", sum);
	 
	return 0;
	
}

int maxSubSequence(int arr[], int N)
{
	//���嵱ǰ�ۻ�֮�ͣ���������ʼֵ����Ϊ0
	int ThisSum, MaxSum = 0;
	int i, j;
	for(i = 0; i <= N; i++){
		ThisSum = 0;
		for(j = i; j <= N; j++) {
			ThisSum += arr[j];
			if(ThisSum > MaxSum){
				MaxSum = ThisSum; 
			}
		}
	}
	return MaxSum;
	
}




















