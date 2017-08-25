#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main()
{

	char buf[MAX];
	char temp[MAX];
	char *ptr;
	int flag = 1;

	memset(buf, '\0', sizeof(buf));
	memset(temp, '\0', sizeof(temp));
	fgets(buf, sizeof(buf)-1, stdin);
	*(buf + strlen(buf) - 1) = '\0';
	ptr = strtok(buf, " ");
	while((NULL != ptr) ) {
		if (isdigit(*ptr)) 
		{
			flag = 0;
			strcat(temp, ptr);	
		}
		ptr = strtok(NULL, " ");
	}
	if(flag == 1)
		printf("%c", '0');
	else
		printf("%s", temp);
	printf("\n");
	return 0;
}
	
