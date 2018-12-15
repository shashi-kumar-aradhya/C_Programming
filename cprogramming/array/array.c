#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr = a;
	int i = 0;
	printf("Address = %p\n", a);
	printf("Address = %p\n", a+1);
	for(i = 0; i< 5; i++, ptr++)
	printf("Address = %p ptr = %p\n", &a[i], ptr);
	return 0;
}
