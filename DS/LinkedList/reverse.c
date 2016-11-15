#include <stdio.h>
#include "Linked.h"
/*#include <stdlib.h>
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
*/
int main()
{
	node *head = NULL;
	int i;
	for(i = 0; i < 5; i++) {
		insert_rear(&head, i);
	}
	printf("*********Original list**********\n");
	display(head);
	reverse(&head);
	printf("\n\n*********reverse list**********\n");
	display(head);
	return 0;
}
