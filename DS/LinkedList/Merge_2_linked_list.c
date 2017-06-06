/* C/C++ program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to insert a node at the beginging of the
   linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
   source, and move it to the front of the dest.
   It is an error to call this with the source list empty.
 
   Before calling MoveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}
 
   Affter calling MoveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3} */
void MoveNode(struct node** destRef, struct node** sourceRef)
{
    /* the front source node  */
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
 
    /* Advance the source pointer */
    *sourceRef = newNode->next;
 
    /* Link the old dest off the new node */
    newNode->next = *destRef;
 
    /* Move dest to point to the new node */
    *destRef = newNode;
}
struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
   
  /* point to the last result pointer */
  struct node** lastPtrRef = &result; 
   
  while(1) 
  {
    if (a == NULL) 
    {
      *lastPtrRef = b;
       break;
    }
    else if (b==NULL) 
    {
       *lastPtrRef = a;
       break;
    }
    if(a->data <= b->data) 
    {
      MoveNode(lastPtrRef, &a);
    }
    else
    {
      MoveNode(lastPtrRef, &b);
    }
   
    /* tricky: advance to point to the next ".next" field */
    lastPtrRef = &((*lastPtrRef)->next); 
  }
  return(result);
}

int main()
{
    /* Start with the empty list */
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
 
    return 0;
}
