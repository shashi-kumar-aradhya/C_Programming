#ifndef __LLIST__
#define __LLIST__

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
ret del_front(node **);
ret del_rear(node **);
ret del_after(node **, node *);
void display(node *);
<<<<<<< HEAD
void reverse(node **head);
=======
>>>>>>> f18f1ef9d2bdb96b701fd2f108d21360f58a1fa2
#endif
