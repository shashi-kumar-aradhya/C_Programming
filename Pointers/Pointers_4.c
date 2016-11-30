#include<stdio.h>
#include<stdlib.h>
void fun(int *a)
{
	printf("i am pointer function\n");
	return;
}
void fun1(int a[])
{
	a = malloc(sizeof(int) * 10);
	printf("i am array function\n");
	return;
}
void print(int a[], int n) 
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n\n");
}
int main() 
{
	int a[5] = {1,2,3,4,5};
	print(a, 5);
	fun(a);
	print(a, 5);
	fun1(a);
	print(a, 5);
	return 0;

} 
