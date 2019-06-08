#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree
{
        int value;
        struct tree *lchild;
        struct tree *rchild;
}node;

typedef struct Stack{
	node *ptr;
#ifdef POSTORDER 
	unsigned vleft :1;   // Visited left?
	unsigned vright :1;  // Visited right?
#endif
	struct	Stack * next;
}stack;

void push(stack ** stack_ptr, node *ptr)
{
	stack *temp = (stack *)malloc(sizeof(stack));
	temp->ptr = ptr;
	temp->next = NULL;
	if(*stack_ptr == NULL)
		*stack_ptr = temp;
	else{
		stack *sptr = *stack_ptr;
		while(sptr->next != NULL)
			sptr = sptr->next;
		sptr->next = temp;
	}
}
node * pop(stack **stack_ptr)
{
	node *ptr = NULL;
	stack *p, *q;
	p = *stack_ptr;
	if(p == NULL)
	{
		printf("Tree is empty\n");
	}
	else if(p->next == NULL)
	{
		ptr = p->ptr;
		*stack_ptr = NULL;
		free(p);
	}
	else
	{
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		ptr = p->ptr;
		q->next = NULL;
		free(p);
	}
	return ptr;
}

bool empty(stack *ptr)
{
	if(ptr == NULL)
		return true;
	return false;
}
node *peek(stack *ptr)
{
	if(ptr == NULL)
		return NULL;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return ptr->ptr;
}
