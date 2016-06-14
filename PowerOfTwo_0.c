#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int number = 0;
	if (argc > 1)
	{
		number = atoi(argv[1]);
	} else {
		printf("Enter the number : ");
		scanf("%d", &number);
	}
	//Heart of the program is below logic
	if (!(number & (number-1))) {
		printf("The number is even\n");
	} else {
		printf("The number is odd\n");
	}
	return 0;
}

