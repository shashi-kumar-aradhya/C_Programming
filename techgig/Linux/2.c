#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * th_f(void *arg);
char *mystring = "Aricent";

int main()
{
        pthread_t ntid;
        char *lptr;
        int status;
        status = pthread_create(&ntid,NULL,th_f, mystring);
        if (status != 0)
        {
                printf("Error in Creating Thread\n");
                exit(status);
        }
        pthread_join(ntid,(void**)&lptr);
        printf("%s\n", lptr);
        pthread_exit(NULL);

}
void *th_f(void *myarg)
{
        printf("New thread: ");
        myarg++;
        pthread_exit((void*)mystring);

}
