#include <stdio.h>
#include <stdlib.h>

void myfunc();
int main()
{
	myfunc();
	return 0;
}  

void myfunc()
{
	int i;
	for (i = 0; i < 10; i++) {
		printf("\n Hello \n");
		sleep(2);
	}
}
