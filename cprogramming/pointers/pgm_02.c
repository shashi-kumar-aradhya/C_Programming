#include <stdio.h>
#include "header.h"

int main(int argc, char *argv[])
{
//	data *ptr = (data *)malloc(sizeof(data));
//	ptr->data = 10;
	data *ptr = atoi(argv[1]);
	printf("I am in : %s, ptr = %p data = %d\n", __FILE__, ptr, ptr->data);
//	sleep(10);
	printf("Exiting from %s\n", __FILE__);
	return 0;
}
