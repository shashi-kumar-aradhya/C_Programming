#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct ll {
	int value;
	struct ll *next;
}list;

#define FREE_LIST(ll_l) 		\
do {					\
	list *ptr = ll_l;		\
	if(ptr != NULL) {		\
	ptr->next = NULL; 		\
	free(ptr);			\
	ptr = NULL;			\
	}				\
}while(0)	

void display(list *head)
{
	while(head != NULL)
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
}
void free_list(list **head)
{
	list *temp = NULL;
	while(*head != NULL)
	{
		temp = *head;
		(*head) = (*head)->next;
		FREE_LIST(temp);
	}
	*head = NULL;
}
void insert(list **head, int value)
{
	list *temp = NULL;
	temp = (list *)malloc(sizeof(list));
	temp->value = value;
	temp->next = *head;
	*head = temp;
}

int main(int argc, char *argv[])
{

	int i;
	int ran_val;
	int MAX = 10;
	int *ptr = NULL;
	int ptr_count = 0;
	if (argc > 1)
		MAX = atoi(argv[1]);
	printf("int total = %d\n", ((MAX / (sizeof(int) * 8)) + 1));
	ptr = (int *) malloc((MAX / (sizeof(int) * 8) + 1));
	list *head = NULL; 
	int div, rem;
	for (i = 0; i < MAX; )
	{
		ran_val = (int)random();
		ran_val = ran_val % MAX;
		div = ran_val / sizeof(int);
		rem = ran_val % sizeof(int);
		if((*(ptr+ div) ) & (1 << rem))
		{
			printf("Skipping value = %d rem = %d div = %d\n", ran_val, rem, div);
			continue;
		}
		*(ptr + div) = (*(ptr+ div) ) | (1 << rem);
		i++;
		insert(&head, ran_val);
	}
	display(head);
//	mergesort(&head);
//	display(head);
	free_list(&head);
	free(ptr);
	return 0;
}
	
