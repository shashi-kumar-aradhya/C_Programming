#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 80
int main(int argc, char *argv[])
{
	char array[MAX];
	int max = 0, store = 0;
	char *ptr = NULL;
	memset(array, '\0', sizeof(array));
	fgets(array, MAX-1, stdin);
	*(array + strlen(array)- 1) = '\0';
	ptr = strtok(array, " ");
	while (ptr != NULL)
	{
		if(isdigit(*ptr))
		{
			store = atoi(ptr);
			if(store > max)
			{
				max = store;
				store = 0;
			}
		}
		ptr = strtok(NULL, " ");
	}
	printf("%d", max);
//	printf("max = %d", max);
	return 0;
}	
