#include <stdio.h>
#include <stdlib.h>
void fun(int *);
int main()
{
	int *a = malloc(sizeof(int));
	*a = 10;
	printf("Main");
	printf("a = %d\n", *a);
	fun(a);
	printf("After fun");
	printf("a = %d\n", *a);
	return 0;
}
void fun(int *a)
{
	printf("in fun");
	printf("a = %d\n", *a);
	*a = 15;
	printf("in fun");
	printf("a = %d\n", *a);
}
