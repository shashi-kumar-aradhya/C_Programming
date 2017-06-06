#include <stdio.h>

void fun(int *p)
{

	*p = 20;
}


int  main()
{
	int a = 10;
	int *p = &a;
	printf("a before call = %d", a);
	fun(p);
	printf("a after call = %d", a);
	return 0;
}

