#include <stdio.h>

//��ඨ��
int N, num[16384], sum[16384];

int maxSubSequence(int A[], int N); 

int main()
{	
	//�������N����������������� 
	printf("������<=100000��������N\n");
	/*scanf()�������Ը�ʽ���еĿո���Ʊ���������ڶ�ȡ����ֵʱ�����������հ׷����ո��Ʊ�������з���*/
	/*scanf���������еĲ���������ָ��*/
	scanf("%d", &N);
//	printf("%d", N);
	if(N > 100000) {
		printf("������С�ڻ��ߵ���100000����!");
	} 
	/*��ȡ�������������������������100000*/
	int i, j;
	for(i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	} 
//	for(j = 1; j <= N; j++){
//		printf("%d\n",num[j]);
//	}
	/*�����������кͺ����������������num������N*/
	
	/*������������������ַ�ʽ 1,�β���һ��ָ�� 2���β���һ���Ѷ����С������ 3���β���һ��δ�����С������*/
	int sum = maxSubSequence(num, N);
//	maxSubSequence(num, N);
	printf("The max subseq is %d\n", sum);
	 
	return 0;
	
}

/*���������������*/
/*��һ�ֱ����ƽ�*/
int  maxSubSequence(int arr[], int N){
	int i, j, k;
		 
	int ThisSum, MaxSum = 0;

	for(i = 1; i <= size; i++) {
		for(j = i; j <= N; j++){
			ThisSum = 0; 
			for(k = i; k <= j; k++){
				ThisSum += arr[k];
			}
			if(ThisSum > MaxSum){
				MaxSum = ThisSum;
			}
		}
	} 
	return MaxSum;
}














