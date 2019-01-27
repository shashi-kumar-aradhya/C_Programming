#include <stdio.h>


static void fun1()
{
	printf("In fun1\n");
	return ;
}

void fun2()
{
	printf("Inside fun2\n");
	fun1();
	return;
}
