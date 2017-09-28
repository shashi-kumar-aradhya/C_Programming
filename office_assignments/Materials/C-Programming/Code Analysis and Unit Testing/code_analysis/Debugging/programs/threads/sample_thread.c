/*    A simple program to demonstrate the POSIX threads  */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *
threadFunction (int cnt)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		printf ("\nhi thread id: %d\n",cnt);
		sleep (1);
	}
}

main ()
{
	pthread_t mythread[2];
	int i;

	for (i = 0; i < 2; i++)
	{
		if (pthread_create (&mythread[i], NULL, (void *)threadFunction,(void *) i))
		{
			printf ("\nerror creating thread");
			exit (1);
		}
	}
	if (pthread_join (mythread[0], NULL))
	{
		printf ("\\nerror joining thread");
		exit (1);
	}
	exit (0);
}
