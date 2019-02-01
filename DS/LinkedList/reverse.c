#include <stdio.h>
#include "Linked.h"

#if 0
#include <stdlib.h>
typedef struct node {
	int value;
	struct node * next;
}node;

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
void display(node* head)
{
	while (head) {
		printf("Value = %d\n", head->value);
		head = head->next;
	}
}
node * create(int value)
{
	node *temp = (node *)malloc(sizeof(node));
	if(!temp) {
		return NULL;
	}
	temp->value = value;
	temp->next = NULL;
	return temp;
}
int insert(node **head, int value)
{
	node *temp = create(value);
	if (!temp) {
		return -1;
	}
	temp->next = *head;
	*head = temp;
	return 0;
}
#endif
node *s_reverse(node *head)
{
	node *temp = NULL;
	node *prev = NULL;
	while(head)
	{
		prev = head;
		head = head->next;
		prev->next = temp;
		temp = prev;
	}
	return prev;
}

int main(int argc, char*argv[])
{
	node *head = NULL;
	if (2 > argc) {
		printf("Usage is : %s number\n", argv[0]);
		return 0;	
	}
	int temp = atoi(argv[1]);
//	int count = atoi(argv[2]);
	int i;
	for(i = 0; i < temp; i++) {
		insert_rear(&head, i +1);
	}
	
	printf("*********Original list**********\n");
	display(head);
//	head = recursiveReverseLL(head);
	head = s_reverse(head);
	printf("\n\n*********reverse list**********\n");
	display(head);
	
#if 0
	circular(head);
	nth_node_end(head, count);
	printf("Before delete = %d\n", list_count(head));
	while(NULL != head) {
		i = rand() % 100;
//		printf("value = %d\n", i);
	
		if( FAILURE == delete_key(&head, i)) 
			printf("Key is already deleted\n");
	
	}
	printf("After delete = %d\n", list_count(head));

	i = rand() % 100;
	if (SUCCESS ==	key_check(head, i))
		printf("Key is present\n");
	i = rand() % 100;
	if (FAILURE ==	key_check(head, i+100))
		printf("Key is not present\n");

	printf("*********Original list**********\n");
	display(head);
	reverse(&head);
	printf("\n\n*********reverse list**********\n");
	display(head);
	middle(head);
#endif
	return 0;
}
