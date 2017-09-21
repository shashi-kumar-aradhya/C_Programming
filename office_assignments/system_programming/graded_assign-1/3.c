#include <stdlib.h>

int main()
{
	printf("Hello world\n");
	fork();
	fork();
	fork();
	fork();
	printf("Hello world\n");
	return 0;
}
