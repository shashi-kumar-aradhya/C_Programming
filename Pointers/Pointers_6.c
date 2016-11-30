#include <stdio.h>

void fun(int a) 
{
	printf("Hello, inside function\n");
	return;
}


int main(void)
{
//	int a[5][1][2];
	int (*a)();
//	int a[5][1];
	printf("Inside main\n");
	fun(a);
	return 0;
}
