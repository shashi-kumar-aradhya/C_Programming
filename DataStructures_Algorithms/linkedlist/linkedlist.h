#ifndef __LINKED_LIST_
#define __LINKED_LIST_
#include "error.h"


typedef struct list{
	struct list * next;
}list;

STATUS_CODES create(list *head);
STATUS_CODES insert_front(list **head, list *  head);


#endif
