#include <stdio.h>
#define TEST	10
int a = 10;

void fun()
{
	a = TEST;
	printf("I am inside fun function and the value = %d\n", a);
	a = a + 10;
	printf("I am inside fun function and the value = %d\n", a);
}

int main()
{
	int i = 0;
	while (i < 5) {
		fun();
		i++;
	}
	return 0;
}
