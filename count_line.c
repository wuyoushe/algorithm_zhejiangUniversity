#include <stdio.h>

main()
{
	int c, nl;
	nl = 0;
	while((c = getchar()) != EOF){
		/*\n��ʾ����*/
		if(c =='\n')
			++nl;
	}
	printf("%d\n", nl);
}
