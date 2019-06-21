#include <stdio.h>

int main()
{
	int i,j,k;
  for(i = 0; i < 4;i++){
  	for(k = 0;k<i;k++){
  		printf(" ");
	  }
    for(j=0;j<4-i;j++){
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}
