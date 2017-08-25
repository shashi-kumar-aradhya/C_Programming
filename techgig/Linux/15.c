#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
        key_t key;
        int shmid;
        char *virtualaddr1 = NULL,*virtualaddr2 = NULL;

        key = ftok("shared.c",'R');
        shmid = shmget(key,1024,0644|IPC_CREAT);

        virtualaddr1 = shmat(shmid,(void*)0,0);
        virtualaddr2 = shmat(shmid,(void*)0,0);

        strcpy(virtualaddr1,"India");
        strcpy(virtualaddr2,"Japan");

        if (fork() == 0)
        {
                strcpy((virtualaddr2 + strlen(virtualaddr2)),"Delhi");
                exit(0);
        }
        wait(NULL);

        printf("%s",virtualaddr1);

        shmdt(virtualaddr1);
        shmdt(virtualaddr2);

        shmctl(shmid,IPC_RMID,0);
        exit(0);

}
