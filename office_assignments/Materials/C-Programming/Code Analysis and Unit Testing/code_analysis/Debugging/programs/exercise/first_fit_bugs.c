#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 64
void *memory_chunk;

typedef struct free_list{
    int size;
    void *addr;
    struct free_list *next;
}free_list_node;

typedef struct busy_list{
    int size;
    void *addr;
    struct busy_list *next;
}busy_list_node;

free_list_node *freeblock = NULL;
busy_list_node *busyblock = NULL;
void init_memory_block();
void execute_choice(int);
int take_user_input();
void * first_fit_alloc(int n);
int my_memfree(void *mem_addr);
void display_free_list();
void display_busy_list();

int main()
{
    init_memory_block();
    int choice ;
    
    while(1)
    {
        choice = take_user_input();

        if (5 == choice)
        {
            break;
        }
        execute_choice(choice);
    }
    
    return 0;
}

void init_memory_block()
{
    /*Initialize the memory chunk */
    memory_chunk = malloc(MAX_MEMORY);

    if (NULL == memory_chunk)
    {
        printf ("ERROR: Malloc failed\n");
        exit(1);
    }
    /*Initialize the free memory list */
    insert_free_list(memory_chunk, MAX_MEMORY);

    /* Initialize the busy list*/
    busyblock = NULL;
}

int take_user_input()
{
    int choice = '\0';
    printf("1: Allocate Memory\n");
    printf("2: Free Memory\n");
    printf("3: Display Free List \n");
    printf("4: Display Busy List \n");
    printf("5: Quit\n");

    printf ("Enter choice(1/2/3/4/5): ");
    scanf("%d",&choice);

    if (( 1 > choice) || (5< choice))
    {
        printf("Program quitting, please enter right choice next time\n");
        exit(1);
    }
    return choice;

}

void execute_choice(int choice)
{
    int size = 0;
    void *alloc = NULL;
    void *addr = NULL;
    int ret_val = 1;
    switch (choice)
    {
        case 1:
            printf("Enter the size of memory to be allocated(<%d): ",MAX_MEMORY);
            scanf("%d",&size);
            alloc = first_fit_alloc(size);

            if (NULL == alloc)
            {
                printf("Memory of size %d cannot be successfully allocated\n");
            }
            else
            {
                printf("Memory of size %d successfully allocated at address 0x%x\n", size, alloc);
            }
            break;

        case 2:
            printf("Enter the address of memory to be freed: ");
            scanf("%x",&addr);
            ret_val = my_memfree((void *)addr);

            if (0 == ret_val)
            {
                printf("Memory at address 0x%x cannot be freed\n ", addr);
            }
            else
            {
                printf("Memory at address 0x%x successfully freed\n ", addr);
            }
            break;

        case 3:
            display_free_list();
            break;

        case 4:
            display_busy_list();
            break;

        default:
            break;
    }
    return;    
}

int  insert_free_list(void *addr, int size)
{
    free_list_node *p = freeblock;

    /* Allocate and initialize new node */
    free_list_node *newnode; 
    newnode->addr = addr;
    newnode->size = size;

    if (NULL == p)
    {
        freeblock = newnode;
    }
    else
    {
        newnode->next = freeblock;
        freeblock = newnode; 
    }
    return 1;
}

int insert_busy_list(void *addr, int size)
{

    busy_list_node *p = busyblock;

    /* Allocate and initialize new node */
    busy_list_node *newnode;

    newnode->addr = addr;
    newnode->size = size;

    if (NULL == p)
    {
        busyblock = newnode;
    }
    else
    {
        newnode->next = busyblock;
        busyblock = newnode; 
    }
    return 1;
}

void display_free_list()
{
    free_list_node *p = freeblock;
    int count = 1;

    if (NULL == p)
    {
        printf("Free list is empty\n");
    }

    while (NULL != p)
    {
        printf ("Free list node : %d\n", count++);
        printf ("Free block address : 0x%x\n", p->addr);
        printf ("Free block size : %d\n\n", p->size);
        p = p->next;
    }
}

void display_busy_list()
{
    busy_list_node *p = busyblock;
    int count = 1;

    if (NULL == p)
    {
        printf("Busy list is empty\n");
    }
    
    while (NULL != p)
    {
        printf ("Busy list node : %d\n", count++);
        printf ("Busy block address : 0x%x\n", p->addr);
        printf ("Busy block size : %d\n\n", p->size);
        p = p->next;
    }
}

void * first_fit_alloc(int n)
{
    int s = 0; /* size of the block */
    free_list_node *p = freeblock; /*traversing variable of the linked list*/
    void *alloc = NULL;
    free_list_node *q = NULL; /*previous node of the traversing variable p*/

    /* Keep scanning till a block of size equal or greater to the requested
     * size is available */
    while (p->size < n)
    {
        q = p;
        p = p->next;
    }

    if (NULL != p)
    {
        s = p->size;
        alloc = p->addr + s - n; /*alloc contains the address of the desired block */

        /* Update the free list */
        if (s == n)
        {
            /* Remove the block from the free list */
            if (NULL == q)
            {
                freeblock = p->next;
            }
            else
            {
                q->next = p->next;
            }
            free ((void *)p);
        }
        else
        {
            p->size = s - n;
        }
        /* Update the  busy list */
        insert_busy_list(alloc, n);
    }
    return alloc;
}

int my_memfree(void *mem_addr)
{
    int s = 0; /* size of the block */
    busy_list_node *p = busyblock; /*traversing variable of the linked list*/
    void *alloc = NULL;
    busy_list_node *q = NULL; /*previous node of the traversing variable p*/

    /* Search for this address's node in the busy link list */
    while(p->addr != mem_addr)
    {
        q = p;
        p = p->next;
    }

    if (NULL != p)
    { 
        /* Retrieve the size of this block of memory */
        s = p->size;

        /* Add this block to the free list */
        insert_free_list(p->addr, p->size);

        /* Remove this block from the busy list */ 
        if (NULL == q)
        {
            busyblock = p->next;
        }
        else
        {
            q->next = p->next;
        }
        free((void *)p);
    }
    return 1; 
}
