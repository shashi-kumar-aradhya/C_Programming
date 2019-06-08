#include <stdio.h>
#include <stdbool.h>

typedef struct tree
{
        int value;
        struct tree *lchild;
        struct tree *rchild;
}node;

typedef struct Stack{
        node *ptr;
        struct  Stack * next;
}stack;

node *peek(stack *ptr);
bool empty(stack *ptr);
node * pop(stack **stack_ptr);
void push(stack ** stack_ptr, node *ptr);


void iterativeInorder (node *root)
 {
//   mynode *save[100];
  // int top = 0;
   stack *STACK = NULL;
 
   while(root != NULL)
   {
       while (root != NULL)
       {
            if (root->rchild != NULL)
            {
             // save[top++] = root->right;
		push(&STACK, root->rchild);
            }
          //  save[top++] = root;
            push(&STACK, root->rchild);
            root = root->lchild;
       }
 
//       root = save[--top];
	root = pop(&STACK);
       while(!empty(STACK) && root->rchild == NULL)
       {
           printf("%d\t", root->value);
           root = pop(&STACK);
       }
 
       printf("%d", root->value);
       //root = !empty(stack) ?pop(&STACK) : (node *) NULL;
	if(!empty(STACK))
		root = pop(&STACK);
	else
		root = NULL;
	
   }
 }

