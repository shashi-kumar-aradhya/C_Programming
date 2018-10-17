#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *ptr;
}NODE;

NODE * fun(NODE *ptr)
{
	
	printf("Fun : Address = %p, &p = %p\n", ptr, &ptr);
	ptr = malloc(sizeof(NODE));
	printf("Fun :after Address = %p, &p = %p\n", ptr, &ptr);
	ptr->value = 10;
	ptr->ptr = NULL;
	return ptr;
}

int main()
{
	NODE *new = NULL, *temp = NULL;
	printf("Address = %p, &p = %p\n", new, &new);
	temp = fun(new);
	printf("Address = %p, &p = %p, temp = %p\n", new, &new, temp);
	return 0;
}
