#include<stdio.h>
int main(void)
{
	static int i = 0;
	for (; i < 10; ) {
		i++;
		printf("i = %d\n", i);
		main(i);
	}
	return 0;
}
		
