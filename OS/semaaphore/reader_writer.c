#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <stdlib.h>
#ifndef MAX
#define MAX 5
#endif

#ifndef SLEEP
#define SLEEP (MAX * 5)
#endif

sem_t mutex,writeblock;
int data = 0,rcount = 0;
int last_change;
int last_thread = -1;
pthread_mutex_t count_mutex;
void fun_2()
{
	pthread_mutex_lock(&count_mutex);
	printf("Exiting from main program\n");
	exit(0);
	pthread_mutex_unlock(&count_mutex);
}
void fun(char *p, const char *func_name, int lineno)
{
	pthread_mutex_lock(&count_mutex);
	printf(p, func_name,lineno);
	pthread_mutex_unlock(&count_mutex);
}
void fun_1(char *p, int f, int data)
{
	pthread_mutex_lock(&count_mutex);
	printf(p, f, data);
	pthread_mutex_unlock(&count_mutex);
}

void *sleep_fun(void *arg)
{
	int sleep_cnt = *(int*)arg;
	sleep(sleep_cnt);
	fun_2();
	return NULL;
}
void *reader(void *arg)
{
	int f;
	f = ((int)arg);
	while(1) {
		sem_wait(&mutex);
		fun("sema_wait : mutex : function name : %s, Line number : %d\n", __func__, __LINE__);
		rcount = rcount + 1;
		if(rcount==1) {
			fun("sema_wait : writeblock : function name : %s, Line number : %d\n", __func__, __LINE__);
			sem_wait(&writeblock);
		}
		fun("sema_post : mutex : function name : %s, Line number : %d\n", __func__, __LINE__);
		sem_post(&mutex);
#if 0
		if ((last_change != data) && (last_thread != f)){
			fun_1("Thread : Data read by the reader : %d is %d\n",f,data);
			last_change = data;
			last_thread = f;
		}
		else 
		fun_1("Threaad : Data read by the reader : %d is %d\n",f,data);
#else

			fun_1("Thread : Data read by the reader : %d is %d\n",f,data);
#endif
		//		sleep(1);
		sem_wait(&mutex);
		fun("sema_wait : mutex : function name : %s, Line number : %d\n", __func__, __LINE__);
		rcount = rcount - 1;
		if(rcount==0) {
			fun("sema_post : writeblock : function name : %s, Line number : %d\n", __func__, __LINE__);
			sem_post(&writeblock);
		}
		fun("sema_post : mutex : function name : %s, Line number : %d\n",__func__, __LINE__);
		sem_post(&mutex);
	}
	return NULL;
}

void *writer(void *arg)
{
	int f;
	f = ((int) arg);
	while(1) {
		sleep(1);
		sem_wait(&writeblock);
		fun("sema_wait : writeblock : function name : %s, Line number : %d\n", __func__, __LINE__);
		data++;
		fun_1("Thread : Data writen by the writer : %d is %d\n",f,data);
		//		sleep(1);
		fun("sema_post : writeblock : function name : %s, Line number : %d\n",__func__, __LINE__);
		sem_post(&writeblock);
	}
	return NULL;
}

int main()
{
	int i; 
	pthread_t rtid[MAX],wtid[MAX], sleep_thread;
	int sleep_cnt = SLEEP;
	sem_init(&mutex,0,1);
	sem_init(&writeblock,0,1);
	pthread_create(&sleep_thread,NULL,sleep_fun,(void *)&sleep_cnt);
	printf("Creating reader and writer threads\n");
	for(i=0;i<MAX;i++)
	{
		pthread_create(&wtid[i],NULL,writer,(void *)i);
		pthread_create(&rtid[i],NULL,reader,(void *)i);
	}
	for(i=0;i<MAX;i++)
	{
		pthread_join(wtid[i],NULL);
		pthread_join(rtid[i],NULL);
	}
	sleep(SLEEP);
	fun_2();
	return 0;
}
