#include <stdio.h>
#include <stdlib.h>
#define N 100001

int main()
{
  int i,n;
  int a[N];
  int sum = 0;
  int MaxSum = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(i = 0; i < n; i++){
    sum+=a[i];//向右累加 
    if(sum>MaxSum)		 
      MaxSum = sum;		//发现更大和则更新当前的结果 
    else if(sum < 0)	//如果当前子列和为负数，则不可能使后面的部分增大，抛弃 
      sum = 0;
  }
  printf("%d\n", MaxSum);
  return 0;
}

