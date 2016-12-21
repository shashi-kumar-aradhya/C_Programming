#ifndef __LLIST__
#define __LLIST__
#include <stdlib.h>
#define SUCCESS 0
#define FAILURE -1

typedef struct node {
	int value;
	struct node *next;
}node;

typedef int ret;
/*
 * Create node
 */

node * create_node(int value);
ret insert_front(node **, int);
ret insert_rear(node **, int);
ret insert_after(node *, int);
ret delete_key(node **, int);
ret del_front(node **);
ret del_rear(node **);
ret del_after(node **, node *);
void display(node *);
void reverse(node **head);
int list_count(node *head);
ret key_check(node *, int);
#endif
