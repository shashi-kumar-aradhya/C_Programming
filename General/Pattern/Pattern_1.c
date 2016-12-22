#include <stdio.h>

int main()
{
	int i, j, input = 0, number = 1;
	printf("Enter the number : ");
	scanf("%d", &input);
	for (i = 0; i < input; i++) {
		for(j = 0; j < i + 1; j++) {
			printf("%d ", number);
			number++;
		}
		printf("\n");
	}
	return 0;
}

