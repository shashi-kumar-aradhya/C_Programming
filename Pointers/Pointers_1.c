#include <stdio.h>
#include <stdlib.h>
void fun(int *);
int main()
{
	int *a;
	int b =10;
	a = &b;
	printf("Main\n");
	printf("a = %d\n", *a);
	fun(a);
	printf("Main\n");
	printf("a = %d\n", *a);
	return 0;
}
void fun(int *a)
{
	int b = 15;
	printf("In fun\n");
	printf("a = %d\n", *a);
	printf("b = %d\n", b);
	a = &b;
	printf("In fun\n");
	printf("a = %d\n", *a);
}
