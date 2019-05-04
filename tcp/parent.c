#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    int pid;
    char *myargs [] = { NULL };
    char *myenv [] = { NULL };

    printf ("Parent: Hello, World! : #%u\n", (unsigned int)getpid());

//Create server program
    pid = fork ();
    if (pid == 0) {
	printf("Creating server\n");
        // I am the child
        execve ("server.exe", myargs, myenv);
    }
    sleep(1);
//Create client program
    pid = fork ();
    if (pid == 0) {
	printf("Creating client\n");
        // I am the child
        execve ("client.exe", myargs, myenv);
    }

    printf ("Parent: exiting\n");
    return 0;
}
