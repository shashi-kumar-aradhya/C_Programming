#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "tlpi_hdr.h"


#define errExitEN(value, string) printf("Error message : return code = %d, from = %s\n", value, string)

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void time_1()
{
  time_t rawtime;
  struct tm * timeinfo;
  pthread_mutex_lock(&lock);        
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );
  pthread_mutex_unlock(&lock);        
}
static void * threadFunc(void *arg)
{    
	int loops = *((int *) arg);    
	int loc, j, s;    
	for (j = 0; j < loops; j++) {        
		printf("Waiting for lock() : %ld\n", pthread_self());
		time_1();
		s = pthread_mutex_lock(&mtx);        
		printf("Acquired lock() : %ld\n", pthread_self());
		if (s != 0)
		    errExitEN(s, "pthread_mutex_lock");
       		loc = glob;        
		loc++;        
		glob = loc;        
		printf("Released lock() : %ld\n", pthread_self());
		s = pthread_mutex_unlock(&mtx);        
		time_1();
		if (s != 0)            
		   errExitEN(s, "pthread_mutex_unlock");    
	}    
	return NULL;

}
int main(int argc, char *argv[])
{    
	pthread_t *t1;
	int i = 0;  
	int loops, s, thread_count;    
//	loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 10000000;    
	loops = (argc > 1) ? atoi(argv[1]) : 10000000;
        thread_count = ((argc > 2) ? atoi(argv[2]) : 3);
	t1 = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
//	thread_count = (thread_count > 10) ? 10 : thread_count; 
	printf("***********Start time ********************\n");
	time_1();
	for (i = 0; i < thread_count; i++) {
	s = pthread_create(&t1[i], NULL, threadFunc, &loops);    
	if (s != 0)        
		errExitEN(s, "pthread_create");
	}    
	for (i = 0; i < thread_count; i++) {
	s = pthread_join(t1[i], NULL);    
	if (s != 0)        
		errExitEN(s, "pthread_join");    
	}
	printf("glob = %d\n", glob);    
	printf("*********** End time ********************\n");
	time_1();
	exit(EXIT_SUCCESS);
}
