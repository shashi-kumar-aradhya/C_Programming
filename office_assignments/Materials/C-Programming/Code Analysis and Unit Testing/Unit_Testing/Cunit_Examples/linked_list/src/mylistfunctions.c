#include "mylist.h"

/************************************************************************
*                       Global variables
************************************************************************/
int g_trace_level = BRIEF_TRACE;
#ifdef TEST_CASE
extern int g_test;
#endif
/*************************************************************************
* Function Name -  set_trace_flag
* Description: Modify the global trace flag as per input param
* Returns: Returns void
**************************************************************************/

void set_trace_flag(int trace_val)
{
    g_trace_level = trace_val;
    A_TRACE(DETAILED_TRACE, ("set_trace_flag: trace flag set to %d\n", g_trace_level));
}

/****************************************************************************
*Function Name -create_new_item
*Description -creates a new node for the linked list
*Arguments - @name and @value which are two members of the node
*Returns - head pointer
****************************************************************************/ 

MYNODE *create_new_item(char *name, int value)
{
        MYNODE *newp;
	
	A_TRACE(DETAILED_TRACE, ("Entering function %s\n", __func__));
        
        newp = malloc(sizeof(*newp));

#ifdef TEST_CASE
	if(1 == g_test)
	newp = NULL;
#endif
        if (NULL == newp)
        {
		A_ERROR(ERROR_CRITICAL, ERROR_MEMORY_FAILURE);
                return NULL;
        }
        newp->name = malloc(strlen(name) + 1);

#ifdef TEST_CASE
	if(2 == g_test)
	newp->name = NULL;
#endif
        if (NULL == newp->name)
        {
		A_ERROR(ERROR_CRITICAL, ERROR_MEMORY_FAILURE);
                free(newp);
                return NULL;
        }
        strcpy(newp->name, name);
        newp->value = value;
        newp->next = NULL;

	A_TRACE(DETAILED_TRACE, ("Exiting  function %s\n", __func__));

        return newp;
}

/****************************************************************************
*Function Name - add_at_front
*Description -adds a node at beginning of the  list
*Arguments -@lisp or the head, and @newp which is the new node
*Returns - head pointer
****************************************************************************/ 

MYNODE *add_at_front(MYNODE *listp, MYNODE *newp)
{
	A_TRACE(DETAILED_TRACE, ("Entering function %s\n", __func__));

        newp->next = listp;
        return newp;

	A_TRACE(DETAILED_TRACE, ("Exiting  function %s\n", __func__));
}

/****************************************************************************
*Function Name - add_at_last
*Description -adds a node at the end of the list
*Arguments -@lisp or the head, and @newp which is the new node
*Returns - head pointer
****************************************************************************/ 

MYNODE *add_at_last(MYNODE *listp, MYNODE *newp)
{
        MYNODE *tempptr;

	A_TRACE(DETAILED_TRACE, ("Entering function %s\n", __func__));
        //if currently list is having no element
        if (NULL == listp)
        {
            return newp;
        }
        //travel till we reach the last node
        for (tempptr = listp; tempptr->next != NULL; tempptr = tempptr->next)
        ; //Null statement 

        tempptr->next = newp;
	A_TRACE(DETAILED_TRACE, ("Exiting  function %s\n", __func__));
        return listp;
}

/****************************************************************************
*Function Name - lookup
*Description -finds the first occurence of a node, with matching name
*Arguments -@listp or the head and @name which is to be matched
*Returns - pointer to the node or NULL(if not found or if  the list is empty)
****************************************************************************/ 

MYNODE *lookup(MYNODE *listp, char *name)
{
	MYNODE  *cur = listp;

	A_TRACE(DETAILED_TRACE, ("Entering function %s\n", __func__));
	while (NULL != cur)
	{
		if (strcmp(cur->name, name) == 0)
		{
			break;
		}
		else
		{
			cur = cur->next;
		}
	}
	A_TRACE(DETAILED_TRACE, ("Exiting  function %s\n", __func__));
	return cur;
}

/****************************************************************************
*Function Name - del_first_item
*Description -deletes a node with a matching name 
*Arguments -@listp or the head and @name which is to be matched and deleted
*Returns - head pointer
****************************************************************************/ 

MYNODE *del_first_item(MYNODE *listp, char *name)
{
	MYNODE  *cur = listp, *prev = listp;

	while (NULL != cur)
	{
		if (strcmp(cur->name, name) == 0)
		{
			//handle case for matching with the first node
			if (listp == cur)
			{
				//Head pointer gets changed, to point to the next node.
				//It may become NULL if there is only one node.
				listp = cur ->next;
			
			}
			else
			{	
				//previous node points to next node, of the current node	
				prev->next = cur->next;
			}
			
			//Now free memory for name inside node
			free(cur->name);
			//free memory for the node
			free(cur);
			//Now break out of  the loop
			break;
		}
		else
		{
			//Remember previous node and point to next node
			prev = cur;
			cur = cur->next;
		}
	}
	return  listp;
}

/****************************************************************************
*Function Name - copy_list
*Description -copies a list
*Arguments -@srcp which is the pointer to the source list
*Returns -pointer to new list
****************************************************************************/ 

MYNODE *copy_list(MYNODE *srcp)
{
	MYNODE* newlist = NULL;
	MYNODE* temp = srcp;

	while (temp != NULL)
	{
		//create nodes corresponding to nodes in the source list
		newlist = add_at_last(newlist, create_new_item(temp->name, temp->value));
		temp = temp->next;
	}	
	return newlist;
}

/****************************************************************************
*Function Name - print_list
*Description -prints a list
*Arguments -@listp which points to the list, to be printed
*Returns - Nothing is returned
****************************************************************************/ 

void print_list(MYNODE *listp)
{
    while (listp != NULL)
    {
            printf("Name is %s  Value is %d\n", listp->name, listp->value);
            listp = listp->next;
    }
}

/****************************************************************************
*Function Name - freeall
*Description -frees (releases memory)a list
*Arguments -@listp which points to the list
*Returns - Nothing is returned
****************************************************************************/ 

void freeall(MYNODE *listp)
{
    MYNODE *curptr = NULL;

    while (listp != NULL)
    {
        curptr = listp;
        listp = listp->next;
        free(curptr->name);
        free(curptr);
    }
}
        
