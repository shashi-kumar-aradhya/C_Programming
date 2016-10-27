#include <stdio.h>
#include <stdlib.h>
void fun(int *);
int main()
{
	int *a;
	int b =10;
	a = &b;
	printf("Main");
	printf("a = %d\n", *a);
	fun(a);
	printf("After fun");
	printf("a = %d\n", *a);
	return 0;
}
void fun(int *a)
{
	int b = 15;
	printf("in fun");
	printf("a = %d\n", *a);
	printf("b = %d\n", b);
	a = &b;
	printf("in fun");
	printf("a = %d\n", *a);
}
