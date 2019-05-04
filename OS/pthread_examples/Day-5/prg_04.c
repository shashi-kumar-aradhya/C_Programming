
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
  
pthread_t tid[2]; 
int counter; 
pthread_mutex_t lock; 
  
void* trythis(void *arg) 
{ 
  int err =  pthread_mutex_lock(&lock); 
    int counter = 1;
    unsigned long i = 0; 
    printf("\n Job %d has started = %d\n", counter); 
  
    //for(i=0; i<(0xFFFFFFFF);i++); 
  
    printf("\n Job %d has finished\n", counter); 
    sleep(5);
  
    printf("\n Job %d sleep has finished\n", counter); 
//    pthreiad_mutex_unlock(&lock); 
  
    return NULL; 
} 


void* trythis_1(void *arg)
{
//    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    int err = -1;
    int counter = 2;
    printf("\n Job %d has started\n", counter);

//    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d has finished\n", counter);

    err = pthread_mutex_unlock(&lock);
        if (err != 0) 
            printf("\nThread can't be created :[%s]", strerror(err)); 
    printf("\n Job %d has finished no err\n", counter);

    return NULL;
}
 


 
int main(void) 
{ 
    int i = 0; 
    int err; 
  
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    while(i < 2) 
    {
	if (i == 0) 
        err = pthread_create(&(tid[i]), NULL, &trythis, NULL); 
	else 
        err = pthread_create(&(tid[i]), NULL, &trythis_1, NULL); 
        if (err != 0) 
            printf("\nThread can't be created :[%s]", strerror(err)); 
        i++; 
    } 
  
    i = 0;
    while(i < 2) { 
    pthread_join(tid[i], NULL); 
    printf("Joining is done i = %d\n", i);
    i++;
   }
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 

