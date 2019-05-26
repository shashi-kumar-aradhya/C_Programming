#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#define _GNU_SOURCE
#include <sched.h>
int main(int argc, char * argv[])
{
	unsigned long new_mask;
	unsigned long cur_mask;
	unsigned int len = sizeof(new_mask);
	pid_t pid;

	if (argc != 3) {
		printf(" usage: %s <pid> <cpu_mask>\n", argv[0]);
		return -1;
	}

//	pid = atol(argv[1]);
//	pid = pthread_self();
	pid = getpid();
	printf("Process id = %d\n", pid);
	sscanf(argv[2], "%08lx", &new_mask);

	if (sched_getaffinity(pid, len, &cur_mask) < 0) {
		printf("error: could not get pid %d's affinity.\n", pid);
		return -1;
	}
	printf(" pid %d's old affinity: %08lx\n", pid, cur_mask);
return 0;

	if (sched_setaffinity(pid, len, &new_mask)) {
		printf("error: could not set pid %d's affinity.\n", pid);
		return -1;
	}

	if (sched_getaffinity(pid, len, &cur_mask) < 0) {
		printf("error: could not get pid %d's affinity.\n", pid);
		return -1;
	}

	printf(" pid %d's new affinity: %08lx\n", pid, cur_mask);

	return 0;
}
