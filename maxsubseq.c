#include <stdio.h>

//简洁定义
int N, num[16384], sum[16384];

int maxSubSequence(int A[], int N); 

int main()
{	
	//定义变量N来接收输入的正整数 
	printf("请输入<=100000的正整数N\n");
	/*scanf()函数忽略格式串中的空格和制表符，此外在读取输入值时，它将跳过空白符（空格，制表符，换行符）*/
	/*scanf函数的所有的参数必须是指针*/
	scanf("%d", &N);
//	printf("%d", N);
	if(N > 100000) {
		printf("请输入小于或者等于100000的数!");
	} 
	/*读取输入的任意整数，存入数组中100000*/
	int i, j;
	for(i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	} 
//	for(j = 1; j <= N; j++){
//		printf("%d\n",num[j]);
//	}
	/*设计求最大子列和函数，传入参数数组num和项数N*/
	
	/*传递数组给函数，三种方式 1,形参是一个指针 2，形参是一个已定义大小的数组 3，形参是一个未定义大小的数组*/
	int sum = maxSubSequence(num, N);
//	maxSubSequence(num, N);
	printf("The max subseq is %d\n", sum);
	 
	return 0;
	
}

/*函数接收数组参数*/
/*第一种暴力破解*/
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














