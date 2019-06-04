#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE       10
#define INT             0
#define FLT             1
#define CHAR            2

#if 0
struct ele {
	int etype;
	union {				//In below example it is assumed we only integer type
		int ival;
		float fvalval;
		char array[50];
	}element;
};

#endif
struct stack {
	int top;
	int items[STACKSIZE];		//Replace with ele
};


//Check stack is empty
int empty(struct stack *ps)
{

	return (ps->top == -1);
}
		
int full(struct stack *ps)
{
	return (ps->top == (STACKSIZE - 1));
}

int pop(struct stack *ps)
{
	if(!(!empty(ps)))
	{
		printf("Stack is empty, pop is not permitted\n");
//		exit(1);
		return -1;
	}
	return (ps->items[ps->top--]);
#if 0
	int value;
	value = ps->items[ps->top];
	ps->top--;
	return value;
#endif 
}
int push(struct stack *ps, int x)
{
	if(!(!full(ps)))
	{
		printf("Stack is full, push is not permitted\n");
		return -1;
//		exit(1);
	}
//	printf("Push top = %d\n", ps->top);
	ps->items[++(ps->top)] = x;
	return 0;
}
int main()
{
	struct stack ele;
	int i = 0;

	memset(&ele, 0, sizeof(ele));
	ele.top = -1;
	for(i=0; i<=10; i++)
	{
		printf("Pushing %d return value = %d\n", i+1, push(&ele, i+1));
	}
	for(i=0; i<=10; i++)
	{
		printf("Popped ele = %d\n", pop(&ele));
	}
	return 0;
}
