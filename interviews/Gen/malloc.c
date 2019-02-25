#include <stdio.h>
#include <stdlib.h>


int main()
{

	int *p = NULL;
	p = (int *)malloc(NULL);
	printf("Address = %p\n", p);
	free(NULL);
	return 0;
}
