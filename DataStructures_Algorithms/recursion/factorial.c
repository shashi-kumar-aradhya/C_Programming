#include <stdlib.h>
#include <stdio.h>

int rec(int val)
{
	if( val == 0 || val == 1)
		return 1;
	return (val * rec(val-1));
}

int main(int argc, char *argv[])
{
	
	printf("Entered value = %d, returned value = %d\n", atoi(argv[1]), rec(atoi(argv[1])));
	return 0;
}

