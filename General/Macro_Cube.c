#include <stdio.h>
#define linear(x) (x)
#define square(x) (x * x)
#define CUBE(x) (x * x * x)
#define FOUR(x) (x * x * x * x)
int main() 
{
	int x = 3, y = 0;
	y = linear(++x);
	printf("x = %d\ty = %d\n", x, y);
	x = 3;
	y = square(++x);
	printf("x = %d\ty = %d\n", x, y);
	x = 3;
	y = CUBE(++x);
	printf("x = %d\ty = %d\n", x, y);
	x = 3;
	y = FOUR(++x);
	printf("x = %d\ty = %d\n", x, y);
	return 0;
}
