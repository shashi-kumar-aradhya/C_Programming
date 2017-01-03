#include <stdio.h>
void print(int value) {
	//printf("Value = %d\n", value);
	if(!value)
		return;
	//printf("Value = %d\n", value);
	print(--value);
	printf("Value = %d\n", value);
}
int main()
{
	print(5);
	return 0;
}
