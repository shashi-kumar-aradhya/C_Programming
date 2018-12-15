#include <stdio.h>
#include <stdlib.h>


int main()
{
	int value ;
	int i  =  0;
	while (i++ < 100) {
	   value = rand()%10;
	switch (value)
	{
		case 1 :
			printf("Value is 1\n");
			break;
		case 2 :
			printf("Value is 2\n");
			break;
		case 3 :
			printf("Value is 3\n");
			break;
		case 4 :
			printf("Value is 4\n");
			break;
		case 5 :
			printf("Value is 5\n");
			break;
		case 6 :
			printf("Value is 6\n");
			break;
		case 7 :
			printf("Value is 7\n");
			break;
		case 8 :
			printf("Value is 8\n");
			break;
		case 9 :
			printf("Value is 9\n");
			break;
		default :
			printf("In default case, it will not reach here\n");
			break;
	}
	}
	return 0;
}
