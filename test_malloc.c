/*一个函数的参数是指向结构的指针 void func(struct COMPLEX *cp)*/
#include <stdlib.h>
#include <stdio.h>

/*该函数由'qsort调用',用于比较整型值*/
int
compare_integers( void const *a, void const *b)
{
	register int const *pa = a;
	register int const *pb = b;
	
	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int 
main()
{
	int *array;
	int n_values;
	int i;
	
	printf("How many values are there? ");
	if(scanf("%d", &n_values) != 1 || n_values <= 0) {
		printf("Illegal number of values.\n");
		exit(EXIT_FAILURE);
	}
	
	array = malloc(n_values * sizeof(int));
	if( array == NULL) {
		printf("Can't get memory for that many values.\n");
		exit(EXIT_FAILURE);
	}
	
	/*读取这些数值*/
	for(i = 0; i < n_values; i += 1) {
		printf("请输入值:");
		if (scanf("%d", array + i) != 1) {
			printf("Error reading value #%d\n", i );
			free(array);
			exit(EXIT_FAILURE);
		}
	}
	
	/*对这些值排序*/
	qsort(array, n_values, sizeof(int), compare_integers );
	
	for (i = 0; i < n_values; i += 1 )
		printf("%d\n", array[i] );
		
	free(array);
	return EXIT_SUCCESS;
}

















