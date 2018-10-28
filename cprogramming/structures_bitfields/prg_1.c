#include <stdio.h>

typedef struct test {
	int a : 4;
	int b : 4;
	int c : 8;
	int d : 12;
	int e : 4;
}TEST;
int main()
{
	int value = 0xffffffff;
	TEST *ptr = (TEST *)&value;
	int i = 0;
	printf("Size = %ld\n", sizeof(TEST));
	for (i = 0; i < 255; i++)
	{
		ptr->a = i;
//		(&(TEST*)value)->a = i;
		printf("i = %d\tValue = 0x%x \t a = 0x%x\n", i, value, ptr->a);
	}
	return 0;
}
