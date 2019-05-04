#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10
void *thread_function(void *);
//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;


void *thread_function(void *dummyPtr)
{
   int sleep_count = *(int *)dummyPtr;
   printf("Entry : Thread number %ld value = #%d\n", pthread_self(), sleep_count);
 //  pthread_mutex_lock( &mutex1 );
   counter++;
 //  pthread_mutex_unlock( &mutex1 );
   sleep((10 - sleep_count) *1); 
   printf("Sleep : Thread number %ld value = #%d\n", pthread_self(), sleep_count);
   pthread_exit(NULL);
}


main()
{
   pthread_t thread_id[NTHREADS];
   int i;
   int array[NTHREADS];


   for(i=0; i < NTHREADS; i++)
   {
      array[i] = i;
      pthread_create( &thread_id[i], NULL, thread_function, (void *)&array[i]);
   }

   for(i=0; i < NTHREADS; i++)
   {
      printf("Waiting Thread number %ld value = #%d\n", thread_id[i], i);
      pthread_join( thread_id[i], NULL); 
   }
  
   /* Now that all threads are complete I can print the final result.     */
   /* Without the join I could be printing a value before all the threads */
   /* have been completed.                                                */

   printf("Final counter value: %d\n", counter);
}

