#include <stdio.h>

typedef void (*callback)(int , int);

void sum(callback fun, int a, int b)
{
	printf("I am inside sum, fun= %p\n", fun); 
	fun(a, b);
}

void user(int a, int b)
{
	printf("I am inside : %s, a = %d\tb = %d\tsum = %d\n", __func__, a, b, a+b);
}
void user_1(int a, int b)
{
	printf("I am inside : %s, a = %d\tb = %d\tsum = %d\n", __func__, a, b, a+b);
}
void user_2(int a, int b)
{
	printf("I am inside : %s, a = %d\tb = %d\tsum = %d\n", __func__, a, b, a+b);
}
int main()
{
	printf("I am inside main\n");
	sum(user,5,10);
	sum(user_1,50,10);
	sum(user_2,500,10);
	return 0;
}
