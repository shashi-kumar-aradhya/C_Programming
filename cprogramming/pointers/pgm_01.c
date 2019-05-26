#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	data *ptr = ( data *)malloc(sizeof( data));
	ptr->data = 10;
	printf("I am in : %s, ptr = %p ,  %d data = %d\n", __FILE__, ptr, (int)ptr, ptr->data);
	sleep(10);
	printf("Exiting from %s\n", __FILE__);
	return 0;
}
