#include <stdio.h>
#include <stdlib.h>

void fun(char *);
int main()
{
	char *ptr = NULL;
	printf("**************In main************");
	printf("Addr = %p\n", ptr);
	fun(ptr);
	printf("**************In main************");
	printf("Addr = %p\n", ptr);
	return 0;
}

void fun(char *ptr)
{
	printf("**************In fun************");
	printf("Addr = %p\n", ptr);
	ptr = (char *)malloc(10);
	printf("**************In fun************");
	printf("Addr = %p\n", ptr);
	return;
}
	
