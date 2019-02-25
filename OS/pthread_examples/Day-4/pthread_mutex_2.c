#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "tlpi_hdr.h"


#define errExitEN(value, string) printf("Error message : return code = %d, from = %s\n", value, string)

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

time_t start_t, end_t;
   double diff_t;



void time_1(int value)
{
//  time_t rawtime;
  struct tm * timeinfo;
  pthread_mutex_lock(&lock);        
  if(value == 0) {
  time ( &start_t);
  timeinfo = localtime ( &start_t );
  } else {
  time ( &end_t );
  timeinfo = localtime ( &end_t);
  }   
  printf ( "Current local time and date: %s", asctime (timeinfo) );
  pthread_mutex_unlock(&lock);
}
static void * threadFunc(void *arg)
{    
	int loops = *((int *) arg);    
	int loc, j, s;    
	time_1(0);
	for (j = 0; j < loops; j++) {        
//		printf("Waiting for lock() : %ld\n", pthread_self());
		s = pthread_mutex_lock(&mtx);        
//		printf("Acquired lock() : %ld\n", pthread_self());
		if (s != 0)
		    errExitEN(s, "pthread_mutex_lock");
       		loc = glob;        
		loc++;        
		glob = loc;        
//		printf("Released lock() : %ld\n", pthread_self());
		s = pthread_mutex_unlock(&mtx);        
		if (s != 0)            
		   errExitEN(s, "pthread_mutex_unlock");    
	}    
	time_1(1);
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
	//time_1();
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
	//time_1();
	diff_t = difftime(end_t, start_t);

	printf("Execution time = %f\n", diff_t);
	printf("Exiting of the program...\n");


	exit(EXIT_SUCCESS);
}
