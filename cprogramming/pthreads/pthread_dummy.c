#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

void *fun(void *rank)
{
	return NULL;
}

int main(int argc, char *argv[])
{
	long thread;
	pthread_t *thread_handles = NULL;
	if (argc < 2) {
		printf("Invalid input\n");
		printf("Input format : %s thread_number\n", argv[0]);
		return 0;
	}
	thread_count = atoi(argv[1]);
	thread_handles = (pthread_t *) malloc(sizeof(pthread_t) * thread_count);

	for(thread = 0; thread < thread_count; thread++)
	{
		pthread_create(&thread_handles[thread], NULL, fun, (void *)thread);
	}

	printf("hello world from main thread\n");

	for(thread = 0; thread < thread_count; thread++)
	{
		pthread_join(thread_handles[thread], NULL);
	}
	
	free(thread_handles);
	return 0;

}
