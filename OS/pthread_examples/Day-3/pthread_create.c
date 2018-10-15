#include <stdio.h>
#include <pthread.h>
int val;

void *child_fn(void * ptr)
{
	val++;
	printf("Value incrementedn in function = %d\n", val);
	return NULL;
}

int main()
{

	pthread_t child;
	printf("Value before thread create = %d\n", val);
	pthread_create(&child, NULL, child_fn, NULL);
	printf("Value after thread create = %d\n", val);
	val++;
	printf("Value incrementedn in main= %d\n", val);
	pthread_join(child, NULL);
	printf("Value  pthread join = %d\n", val);
	return 0;
}


