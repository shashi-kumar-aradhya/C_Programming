#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
	struct node *next;
	char *d_ptr;
	struct node *prev;
}NODE;

int duplicate(NODE *head, char *ptr)
{
	while(head != NULL) 
	{
		if(0 == strcmp(head->d_ptr, ptr))
			return 1;
		head = head->next;
	}
	return 0;
}
void insert(NODE **head, NODE **tail, char *str)
{
	if (0 != duplicate(*head, str))
		return;
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	if(NULL != temp) {
		temp->d_ptr = malloc(strlen(str) + 1);
		strcpy(temp->d_ptr, str);
		if(*head == NULL) {
			*head = *tail = temp;
			 (*head)->next = NULL;
			 (*head)->prev= NULL;
		} else {
			temp->next = NULL;
			temp->prev = (*tail);
			(*tail)->next = temp;
			(*tail) = temp;
		}
	}
	
}
void print_rev(NODE*ptr)
{
	while(NULL != ptr) {
		printf("%s ", ptr->d_ptr);
		ptr = ptr->prev;
	}
}
void del(NODE** head)
{
	NODE *temp = *head;
	NODE *ptr;
	while(NULL != temp->next) {
		ptr = temp;
		temp = temp->next;
		free(ptr->d_ptr);
		free(ptr);
	}
	*head = NULL;
}
int main()
{

	char buf[MAX];
	char *ptr;
	NODE *head =NULL, *tail = NULL;
	memset(buf, '\0', sizeof(buf));
	fgets(buf, sizeof(buf)-1, stdin);
	*(buf + strlen(buf) - 1) = '\0';
	ptr = strtok(buf, " ");
	while((NULL != ptr) && (0 != strcmp("END", ptr))) {
		insert(&head, &tail, ptr);
		ptr = strtok(NULL, " ");
	}
	print_rev(tail);
	del(&head);
	printf("\n");
	return 0;
}
	
