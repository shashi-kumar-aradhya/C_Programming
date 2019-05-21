#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,writeblock;
int data = 0,rcount = 0;

void *reader(void *arg)
{
	int f;
	f = ((int)arg);
	sem_wait(&mutex);
	printf("sema_wait : mutex : %s %d\n", __func__, __LINE__);
	rcount = rcount + 1;
	if(rcount==1) {
		printf("sema_wait : writeblock : %s %d\n", __func__, __LINE__);
		sem_wait(&writeblock);
	}
	printf("sema_post : mutex : %s %d\n", __func__, __LINE__);
	sem_post(&mutex);
	printf("Thread : Data read by the reader%d is %d\n",f,data);
//	sleep(1);
	sem_wait(&mutex);
	printf("sema_wait : mutex : %s %d\n", __func__, __LINE__);
	rcount = rcount - 1;
	if(rcount==0) {
		printf("sema_post : writeblock : %s %d\n", __func__, __LINE__);
		sem_post(&writeblock);
	}
	printf("sema_post : mutex : %s %d\n",__func__, __LINE__);
	sem_post(&mutex);
}

void *writer(void *arg)
{
	int f;
	f = ((int) arg);
	sem_wait(&writeblock);
		printf("sema_wait : writeblock : %s %d\n", __func__, __LINE__);
	data++;
	printf("Thread : Data writen by the writer%d is %d\n",f,data);
	//	sleep(1);
	printf("sema_post : writeblock : %s %d\n",__func__, __LINE__);
	sem_post(&writeblock);
}

int main()
{
	int i,b; 
	pthread_t rtid[5],wtid[5];
	sem_init(&mutex,0,1);
	sem_init(&writeblock,0,1);
	for(i=0;i<=2;i++)
	{
		pthread_create(&wtid[i],NULL,writer,(void *)i);
		pthread_create(&rtid[i],NULL,reader,(void *)i);
	}
	for(i=0;i<=2;i++)
	{
		pthread_join(wtid[i],NULL);
		pthread_join(rtid[i],NULL);
	}
	return 0;
}
