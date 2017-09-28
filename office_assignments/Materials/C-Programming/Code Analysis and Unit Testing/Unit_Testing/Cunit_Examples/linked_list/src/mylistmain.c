#include "mylist.h"


int main(int argc, char *argv[])
{
    MYNODE *head = NULL, *nodeptr, *newhead = NULL;

    if (argc > 1)  /* trace flag data provided */
    {
        set_trace_flag(atoi(argv[1]));
    }

    //build the list 
    nodeptr = create_new_item("data1", 10);
    A_TRACE(BRIEF_TRACE, ("Created a New Item %s %d\n", nodeptr->name, nodeptr->value));

    head = add_at_front(head, nodeptr);
    A_TRACE(BRIEF_TRACE, ("Added at front \n"));

    nodeptr = create_new_item("data2", 100);
    head = add_at_front(head, nodeptr);

    nodeptr = create_new_item("data3", 150);
    head = add_at_last(head, nodeptr);

    nodeptr = create_new_item("data4", 1250);
    head = add_at_last(head, nodeptr);

    print_list(head);

    //Looking up for a value
    nodeptr = lookup(head, "data1");
    if (NULL != nodeptr)
    {
	printf("Found!! Name is %s value is %d\n", nodeptr->name, nodeptr->value);
    }

    //Creating a new list which is duplicate of  the old list
    newhead = copy_list(head);

    //printing the new  list
    printf("Printing a new list\n");
    print_list(newhead);
	
    //delete an item and print the list
    newhead = del_first_item(newhead, "data3");
    printf("Printing a new list after deletion\n");
    print_list(newhead);
	

    freeall(head);
    freeall(newhead);
    return 0;
}

    

