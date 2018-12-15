#include <stdio.h>
#include <stdlib.h>


int main()
{
	int value ;
	int i  =  0;
	while (i++ < 100) {
	   value = rand()%10;
		if (1 == value) 
			printf("Value is 1\n");
		else if (2 == value) 
			printf("Value is 2\n");
		else if (3 == value) 
			printf("Value is 3\n");
		else if (4 == value) 
			printf("Value is 4\n");
		else if (5 == value) 
			printf("Value is 5\n");
		else if (6 == value) 
			printf("Value is 6\n");
		else if (7 == value) 
			printf("Value is 7\n");
		else if (8 == value) 
			printf("Value is 8\n");
		else if (9 == value) 
			printf("Value is 9\n");
		else  
			printf("In else case, value is 0\n");
	}
	return 0;
}
