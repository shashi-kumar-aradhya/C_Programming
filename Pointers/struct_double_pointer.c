#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *ptr;
}NODE;

struct new {
	int count;
	NODE *ptr;
};
NODE * fun(NODE **ptr)
{
	
	printf("Fun : &ptr = %p\n", &ptr);
	printf("Fun : ptr = %p\n", ptr);
	printf("Fun : *ptr = %p\n", *ptr);
	NODE *ptr1 = (NODE *)malloc(sizeof(NODE));
		
	printf("Fun : ptr1 = %p\n", ptr1);
	ptr1->value = 10;
	ptr1->ptr = NULL;
	*ptr = ptr1;
	return ptr1;


}
int main()
{
	struct new *temp = (struct new *) malloc(sizeof(struct new));
	temp->ptr = NULL;
	printf("Main : &temp = %p\n", &temp);
	printf("Main : temp->ptr = %p\n", temp->ptr);
	printf("Main : &temp->ptr = %p\n", &temp->ptr);
	NODE *ptr = fun(&temp->ptr);
	printf("Main : returned temp->ptr = %p\n", temp->ptr);
	printf("Main : returned &temp->ptr = %p\n", &temp->ptr);
	printf("Main : returned pointer = %p\n", ptr);
	printf("Main : returned temp->ptr->value = %d\n", temp->ptr->value);
	printf("Main : returned temp->ptr->ptr = %p\n", temp->ptr->ptr);
	return 0;
}
	

	