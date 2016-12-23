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
	/*        if (!test || !test->next) {
		  return;
		  }
	 */
	while (test) {
		prev = test->next;
		test->next = temp;
		temp = test;
		test = prev;
	}
	//test->next = temp;
	*head = temp;
}

ret delete_key(node **head, int key)
{
	node * prev = NULL;
	node * cur = *head;
	/* check till end of list/key is present*/	
	while((NULL != cur) && (key != cur->value)) {
		prev = cur;
		cur = cur->next;	
	}
	/*if key is present*/
	if(NULL != cur) {
		/*not first element*/
		if (prev != NULL) {
			prev->next = cur-> next;
		} else {
			*head = cur->next;
		}
		free(cur);
		return SUCCESS;
	}
	return FAILURE;
}

int list_count(node *head)
{
	if(head != NULL)
		return (1 + list_count(head->next));
	return 0;
}

ret key_check(node *head, int key)
{
	if((NULL != head) && (key != head-> value)) 
		return key_check(head->next, key);
	if(NULL == head)
		return FAILURE;
	return SUCCESS;
}
void middle(node *head)
{
	node *fast = head;
	node *slow = head;
	if(NULL == fast) {
		printf("Empty list\n");
		return ;
	}	
	while((NULL != fast) && (NULL != fast->next)) {
		fast = fast->next->next;
		slow = slow->next;
	}	
	printf("Middle node value = %d\n",slow->value);
	return;
}

void nth_node_end(node *head, int count)
{
	node *temp = head;
	while((0 !=  count) && (NULL != head)) {
		head = head->next;
		count--;
	}
	if (count > 0) {
		printf("Insufficient number of nodes\n");
		return;
	}
	while (NULL != head) {
		head = head->next;
		temp = temp->next;
	}
	printf("n-th node : %d\n", temp->value);
	return;
}
void circular(node *head)
{
	
	node * slow =  head;
	node * temp =  head;
	//Checking empty list
	if (NULL == head) {
		printf("Empty List\n");
		return;
	}
	//For making circular list	
	while (NULL != temp && NULL != temp->next) {
		temp = temp->next;
	}
	temp->next = head;

	//checking circular list
	while ((NULL != head) && (NULL != head->next)) {
		printf("Head = %d\tslow = %d\n", head->value, slow->value);
		head = head->next->next;
		slow = slow->next;
		if(slow != head)
			break;
	}
	if (slow == head) {
		printf("Given linked list circular\n\n");
	} else {
		printf("Given linked list not circular\n\n");
	}
	return;
}
	
