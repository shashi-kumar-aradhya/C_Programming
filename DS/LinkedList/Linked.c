#include <stdio.h>
#include <stdlib.h>
#include "Linked.h"

node * create_node(int value) 
{
	node * temp = NULL;
	temp = (node *)malloc(sizeof(node));
	if (NULL == temp) {
		return NULL;
	}
	temp->value = value;
	temp->next = NULL;
	return temp;
}

ret insert_front(node ** head, int value)
{
	node *temp = create_node(value);
	if (NULL == temp) {
		return FAILURE;
	}
	temp->next = *head;
	*head = temp;
	return SUCCESS;
}
ret insert_rear(node **head, int value)
{
	node *temp = create_node(value);
	node *ptr = *head;
	if (NULL == temp) {
		return FAILURE;
	}
	if (NULL == *head) {
		*head = temp;
		return SUCCESS;
	}
	while (NULL != ptr->next) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	return SUCCESS;
}
ret insert_after(node *head, int value)
{
	node *temp = create_node(value);
	if (NULL == temp) {
		return FAILURE;
	}
	temp->next = head->next;
	head->next = temp;
	return SUCCESS;
}

void display(node *head)
{
	while (NULL != head) {
		printf("Value = %d\n", head->value);
		head = head->next;
	}
	return;
}
void reverse(node **head)
{
        node *prev = NULL;
        node *temp = NULL;
        node *test = *head;
        if (!test || !test->next) {
                return;
        }
        while (test->next) {
                prev = test->next;
                test->next = temp;
                temp = test;
                test = prev;
        }
        test->next = temp;
        *head = test;
}

