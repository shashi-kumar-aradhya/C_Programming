#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid;
	int i = 0;
	int *ptr = (int *)malloc(sizeof(int) * 25);
	printf("Parent process pid = %d\talloc = %p\n", getpid(), ptr);
	if((pid = fork()) == 0)
	{
		int *ptr_1 = (int *)malloc(sizeof(int) * 5);
		ptr_1[0] = 10;
		while(i < 10){
			printf("Child process pid = %d\talloc = %p, value = %d, i = %d\n", getpid(), ptr_1, ptr_1[0], i);
			sleep(5);
			ptr_1[0] += i++;
		}
	}
	else
	{
		int *ptr_1 = (int *)malloc(sizeof(int) * 5);
		ptr_1[0] = 20;
		sleep(20);
		while(i < 10){
			printf("Parent process pid = %d\talloc = %p, value = %d, i = %d\n", getpid(), ptr_1, ptr_1[0], i);
			sleep(15);
			ptr_1[0] += i++;
		}

	}
	return 0;
}
