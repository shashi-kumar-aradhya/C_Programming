#include <stdio.h>

int largest_power(int N)
{
	//changing all right side bits to 1.
	N = N| (N>>1);
	N = N| (N>>2);
	N = N| (N>>4);
	N = N| (N>>8);
	//as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by     2. 
	return (N+1)>>1;
}
int main()
{
	int input;
	while (1)
	{
		printf("Enter input : ");
		scanf("%d", &input);
		printf("Largest power : %d\n", largest_power(input));
	}
	return 0;
}
