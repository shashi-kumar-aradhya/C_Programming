#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXBUF 10

void *doit(void *);
int fd;
int main()
{
        char buf[MAXBUF]; 
        pthread_t th1;
        int ret;
        ret = pthread_create(&th1,NULL,doit,NULL);
        if (ret)
        {
                printf("Error in Creating Thread\n");
                exit(EXIT_FAILURE);
        }

        ret = pthread_join(th1,NULL);
        if (ret)
        {
                printf("Error in Joining Thread\n");
                exit(EXIT_FAILURE);
        }
        ret = read(fd,buf,MAXBUF);
        if (-1 == ret)
        {
                printf("Main : Error in reading File\n");
                exit(EXIT_FAILURE);
        }
        buf[ret] = '\0';
        printf("Read By main: %s\n",buf);
        exit(EXIT_SUCCESS);
}
void *doit(void *ptr)
{
        int i;
        char buf[MAXBUF];
        fd = open("sample",O_RDONLY);
        if (-1 == fd)
        {
                printf("Error in opening the File\n");
                pthread_exit(NULL);
        }
         i = read(fd,buf,2);
        buf[i] = '\0';
        printf("Read By thread: %s\n",buf);
        pthread_exit(NULL);
}

