#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


typedef struct list {
	int data;
	struct list *ptr;
}list;

typedef enum {
	FAILURE 		=-1,
	SUCCESS 		=0,
	INSERTLIST_FAILURE 	=1,
	MEMALLOC_FAILURE 	=2,
	STACK_EMPTY 		=3,
	STACK_FULL		=4,
	QUEUE_EMPTY		=5,
	QUEUE_FULL		=6,
	LIST_EMPTY		=7,
}STATUS_CODE;

STATUS_CODE insert_front(list **head, int data);
void* create_list(int data);

#endif 
	
