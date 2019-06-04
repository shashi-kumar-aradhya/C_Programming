#include <stdio.h>
#include <stdlib.h>

int fibo(int value)
{
	if( value == 0 || value == 1)
		return value;
	return (fibo(value-2) +fibo(value-1));
}

int main(int argc, char *argv[])
{
	printf("Fib = %d\tFib res= %d\n", atoi(argv[1]), fibo(atoi(argv[1])));
	return 0;
}
