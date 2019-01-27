#include <stdio.h>

extern void fun1();
extern void fun2();
int main()
{
	printf("In main\n");
	fun1();
	fun2();
	return 0;
}
