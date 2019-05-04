#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid;
	int i = 0;
	int *ptr = (int *)malloc(sizeof(int) * 25);
	printf("process : 1 pid = %d\talloc = %p\n", getpid(), ptr);
	sleep(20);
	return 0;
}
