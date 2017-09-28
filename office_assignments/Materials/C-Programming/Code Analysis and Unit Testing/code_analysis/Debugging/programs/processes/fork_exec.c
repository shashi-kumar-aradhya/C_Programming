#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

main() {
	pid_t pid = 0;
	int i = 0;
	printf("process id : %u\n", getpid());
	pid = fork();
	if (pid == 0) 
	{
		execlp("./childprogram", "childprogram", NULL);
	}
	printf("parent process \n");
	return 1;
}
