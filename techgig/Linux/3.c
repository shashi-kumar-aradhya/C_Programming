#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printme(void *th)
{
  int *p;
  p=(int*)th;
  printf("I am Thread %d\n",*p);
  free(th);
  pthread_exit(NULL);
}

int main()
{
        pthread_t threads[5];
        int t;
        int *iptr;
        for(t = 0; t < 5; t++)
        {
                iptr = (int*)malloc(sizeof(int));
                *iptr=t;
                pthread_create(&threads[t],NULL,printme,iptr);
        }
        pthread_exit(NULL);
}
