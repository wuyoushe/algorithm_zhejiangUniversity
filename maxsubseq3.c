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
    sum+=a[i];//�����ۼ� 
    if(sum>MaxSum)		 
      MaxSum = sum;		//���ָ��������µ�ǰ�Ľ�� 
    else if(sum < 0)	//�����ǰ���к�Ϊ�������򲻿���ʹ����Ĳ����������� 
      sum = 0;
  }
  printf("%d\n", MaxSum);
  return 0;
}

