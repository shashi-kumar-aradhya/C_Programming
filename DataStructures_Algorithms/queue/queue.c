#include <stdio.h>
#include <stdlib.h>

#define MAX 10

#define TRUE 0
#define FALSE -1

struct queue {
	int items[MAX];
	int front, rear;
	int size;
};

void create(struct queue *pq)
{
	pq->front = pq->size = 0;
	pq->rear  =  MAX - 1;

}

int isFull(struct queue *pq)  
{ 
	return ((pq->size == MAX) ? TRUE : FALSE) ;
}

int isEmpty(struct queue* pq)  
{ 
	return ((pq->size == 0) ? TRUE : FALSE);
}

void enqueue(struct queue * pq, int items)  
{  
    if (TRUE == isFull(pq))  
    {
	printf("Queue is full, enqueue is not possible\n");
	return;
    }
    pq->rear = (pq->rear + 1) % MAX;  
    pq->items[pq->rear] = items;  
    pq->size = pq->size + 1;  
//    cout << items << " enqueued to queue\n";  
    printf("items : %d  enqueued to queue\n", items);  
}

int dequeue(struct queue *pq)  
{  
    if (TRUE == isEmpty(pq))
    {
	printf("Queue is empty : ");
        return FALSE;  
    }
    int items = pq->items[pq->front];  
    pq->front = (pq->front + 1) % MAX;  
    pq->size = pq->size - 1;  
    return items;  
}

int front(struct queue *pq)  
{  
    if (isEmpty(pq))  
        return FALSE;  
    return pq->items[pq->front];  
}
int rear(struct queue *pq)  
{  
    if (isEmpty(pq))  
        return FALSE;  
    return pq->items[pq->rear];  
}

int main()
{
	int i;
	struct queue q;
	create(&q);
	for(i = 0; i<=MAX; i++)
	{
		enqueue(&q, (rand()%(MAX * 10)));
	}
	for(i = 0; i<=MAX; i++)
	{
		printf("Dequeued value = %d\n", dequeue(&q));
	}
	return 0;
}
