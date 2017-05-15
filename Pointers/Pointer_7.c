#include <stdio.h>

typedef struct node {
	int data;
	struct node *ptr;
}node;

int main()
{
	node a;
	node *result;
	node **lastptr = &result;
	return 0;
}
