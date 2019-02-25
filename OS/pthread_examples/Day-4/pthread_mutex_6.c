#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "tlpi_hdr.h"


#define errExitEN(value, string) printf("Error message : return code = %d, from = %s\n", value, string)

static int glob = 0;
//static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mtx;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

time_t start_t, end_t;
   double diff_t;

typedef void*  (*fn) (void *);

volatile int check = 0;
void time_1(int value)
{
//  time_t rawtime;
  struct tm * timeinfo;
  pthread_mutex_init(&mtx, NULL);
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
void * f1(void *arg)
{    
	int loops = *((int *) arg);    
	int loc, j, s;    
	time_1(0);
	printf("f1 entry () : %ld\n", pthread_self());
	s = pthread_mutex_lock(&mtx);        
	if (s != 0)
	    errExitEN(s, "pthread_mutex_lock");
	 printf("pthread_mutex_lock acquired by : %ld\n", pthread_self());
	for (j = 0; j < loops; j++) {        
//		printf("Waiting for lock() : %ld\n", pthread_self());
//		printf("Acquired lock() : %ld\n", pthread_self());
       		loc = glob;        
		loc++;        
		glob = loc;        
//		printf("Released lock() : %ld\n", pthread_self());
	}    
	s = pthread_mutex_unlock(&mtx);        
	printf("pthread_mutex_lock released by : %ld\n", pthread_self());
	if (s != 0)            
	   errExitEN(s, "pthread_mutex_unlock");    
	time_1(1);
	printf("f1 exit () : %ld\n", pthread_self());
	return NULL;
}
void * f2(void *arg)
{    
	int loops = *((int *) arg);    
	int loc, j, s;    
	time_1(0);
	printf("f2 entry () : %ld\n", pthread_self());
	s = pthread_mutex_lock(&mtx);        
	if (s != 0)
	    errExitEN(s, "pthread_mutex_lock");
	 printf("pthread_mutex_lock acquired by : %ld\n", pthread_self());
	for (j = 0; j < loops; j++) {        
//		printf("Waiting for lock() : %ld\n", pthread_self());
//		printf("Acquired lock() : %ld\n", pthread_self());
       		loc = glob;        
		loc++;        
		glob = loc;        
//		printf("Released lock() : %ld\n", pthread_self());
	}    
	check = 1;
	s = pthread_mutex_unlock(&mtx);        
	printf("pthread_mutex_lock released by : %ld\n", pthread_self());
	if (s != 0)            
	   errExitEN(s, "pthread_mutex_unlock");    
	time_1(1);
	printf("f2 exit () : %ld\n", pthread_self());
	return NULL;
}
static void * f3(void *arg)
{    
	int loops = *((int *) arg);    
	int loc, j, s;    
	time_1(0);
	printf("f3 entry () : %ld\n", pthread_self());
	
	while(check != 1) ;
	s = pthread_mutex_lock(&mtx);        
	printf("pthread_mutex_lock  acquired by : %ld\n", pthread_self());
	if (s != 0)
	    errExitEN(s, "pthread_mutex_lock");
	for (j = 0; j < loops; j++) {        
//		printf("Waiting for lock() : %ld\n", pthread_self());
//		printf("Acquired lock() : %ld\n", pthread_self());
       		loc = glob;        
		loc++;        
		glob = loc;        
//		printf("Released lock() : %ld\n", pthread_self());
	}    
	s = pthread_mutex_unlock(&mtx);        
	printf("pthread_mutex_lock released by : %ld\n", pthread_self());
	if (s != 0)            
	   errExitEN(s, "pthread_mutex_unlock");    
	time_1(1);
	printf("f3 exit() : %ld\n", pthread_self());
	return NULL;

}
fn fun[3] = {f1, f2, f3};
int main(int argc, char *argv[])
{    
	pthread_t *t1;
	int i = 0;  
	int loops_1, loops[3], s, thread_count;    
//	loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 10000000;    
	loops_1 = (argc > 1) ? atoi(argv[1]) : 10000000;
//        thread_count = ((argc > 2) ? atoi(argv[2]) : 3);
	thread_count = 3;
	t1 = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
//	thread_count = (thread_count > 10) ? 10 : thread_count; 
	printf("***********Start time ********************\n");
	//time_1();
	//for (i = 0; i < thread_count; i++) {
	for (i = 0; i < thread_count; i++) {
	loops[i] = loops_1; 
	s = pthread_create(&t1[i], NULL, fun[i], &loops[i]);    
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
