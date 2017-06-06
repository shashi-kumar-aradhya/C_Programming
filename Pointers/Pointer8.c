#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
	when p = "kumar" we are changing in value in local variable
	when strcpy(p, "kumar"), we are copying to same address
*/
void fun(char *p)
{
//	strcpy(p, "kumar");
	p = "kumar";
	printf("In function address = %p\n", p);
}


int  main()
{
//	char *p = malloc(10);	 
//	strcpy(p, "shashi");
	char *p = "shashi";
	printf("a before call = %s\n", p);
	fun(p);
	printf("a after call = %s\n", p);
	return 0;
}

