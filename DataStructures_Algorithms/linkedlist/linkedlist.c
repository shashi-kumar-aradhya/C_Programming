#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "error.h"

struct temp {
        struct list* next;
        int data;
};

STATUS_CODES insert_front(list *insert, list **head)
{
	insert->next = *head;
	*head = insert;
	return STATUS_OK;
}
STATUS_CODES insert_rear(list *insert, list **head)
{
	if (NULL == *head)
	   *head = insert;
	list *temp = *head;
	while(NULL != temp->next)
		temp = temp->next;
	temp->next = insert;
	return STATUS_OK;
}

int main()
{
	list *head = NULL;
	
	int i = 0;
	struct temp *input = NULL;
	struct list *ptr = NULL;
	for(i=0; i<5; i++)
	{
		input = (struct temp *)malloc(sizeof(struct temp));
		if(input == NULL)
		{
			printf("Memory allocation is failed\n");
			return 1;
		}
		input->next = NULL;
		input->data = i;
		insert_front((list *)&input, &head);
	}
	for(i=0; i<5; i++)
        {   
                input = (struct temp *)malloc(sizeof(struct temp));
                if(input == NULL)
                {   
                        printf("Memory allocation is failed\n");
                        return 1;
                }   
                input->next = NULL;
                input->data = i+10;
                insert_rear((list *)&input, &head);
        }  
	ptr = head->next;
	while(ptr->next != NULL)
	{
		printf("Value = %d\n", ((struct temp *)ptr)->data);
		ptr = ptr->next;
	}
	return 0;
}

