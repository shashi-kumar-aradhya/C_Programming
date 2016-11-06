#include <stdio.h>
#include <stdlib.h>
void fun(int *);
int main()
{
	int *a = malloc(sizeof(int));
	*a = 10;
	printf("Main\n");
	printf("a = %p\n", a);
	printf("*a = %d\n", *a);
	fun(a);
	printf("After fun\n");
	printf("a = %p\n", a);
	printf("*a = %d\n", *a);
	return 0;
}
void fun(int *a)
{
	printf("In fun\n");
	printf("a = %p\n", a);
	printf("*a = %d\n", *a);
	a = malloc(sizeof(int));
	*a = 15;
	printf("In fun\n");
	printf("a = %p\n", a);
	printf("*a = %d\n", *a);
}
