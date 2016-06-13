#include <stdio.h>
#include <malloc.h>
int main() 
{
	int *ptr = (int *)malloc(4);
	char *str = (char *)malloc(1);
	printf("ptr = %d\tstr = %d\n\n", (int)ptr, (int)str);
	printf("Ele = %d\n", sizeof(*ptr));
	int ptr_1= (int)ptr;
	int str_1= (int)str;
	printf("ptr_0 = %d\tstr = %d\n\n", (int)ptr_1, (int)str_1);
	printf("diff = %d\n\n", (int)str - (int)ptr);
	printf("diff_1 = %d\n\n", (int)str_1 - (int)ptr_1);
	printf("Done !!\n");
	return 0;
}
