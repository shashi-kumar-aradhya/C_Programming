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




void iterativePreorder(node *root)
 {
//   mynode *save[100];
//   int top = 0;
   stack *STACK = NULL ;
   if (root == NULL)
   {
     printf("Empty list\n");
     return;
   }
 
//   save[top++] = root;
   push(&STACK, root);
   while (!empty(STACK))
   {
     root = pop(&STACK);
 
     printf("%d\t", root->value);
 
     if (root->rchild != NULL)
       push(&STACK, root->rchild);
     if (root->lchild != NULL)
        push(&STACK,root->lchild);
   }
  
 }

