#include <stdio.h>
#include <malloc.h>
int main() 
{
	int * ptr = (int *)malloc(sizeof(int) * 10),
	    * str = (int *)malloc(sizeof(int) * 20);
	printf("ptr = %d\tstr = %d\n", (int)ptr, (int)str);
	printf("diff = %d\n", str - ptr);
	//printf("sum = %d\n", (str + ptr) );
	//printf("mul = %d\n", (str * ptr) );
	//printf("div = %d\n", (str \ ptr) );
	return 0;
}
