//#include "l_list.h"
#include "LinkedList.h"

/**************************************************************
*Fun name : 	add_tail
*Param : 	Base address of LL holder, Linked list element
*Functionality: Adds element at the end of the list
***************************************************************/
/************
*Verified
************/
void add_tail(LL **list_ptr, LL *ptr)
{
	LL *temp = *list_ptr;
	//Check Null pointer 
	if (ptr == NULL)
		return;

	//If list is empty
	if (*list_ptr == NULL) {
		*list_ptr = ptr;
	} else {
		//Traverse till the end of the list
		//Check For Correction
		while(!temp && temp->next)
			temp = temp->next;
		temp->next = ptr;
	}
}


/****************************************************
*Fun name : 	add_tail
*Param : 	Base address of LL holder, Linked list element
*Functionality: Adds element at the starting of the list
****************************************************/
/************
*Verified
************/
void add_head(LL **list_ptr, LL *ptr) 
{
	
	//Check Null pointer 
	if (ptr == NULL)
		return;
	//Add at the start of the list
	ptr->next = *list_ptr;
	*list_ptr = ptr;
}

/****************************************************************
*Fun name : 	del
*Param : 	Base address of LL holder, Linked list element
*Functionality: Delete the given ele from the list
*****************************************************************/
/************
*Verified
************/
void del(LL **list_ptr, LL *ptr)
{
	LL *temp = *list_ptr;
	//Null pointer check
	if (!(*list_ptr) || !ptr)
		return;
	
	//Check first element
	if (temp == ptr) {
		(*list_ptr) = temp->next;
	} else {
		//Traverse till the end or element found
		while (!temp && !(temp->next) && (temp->next != ptr)) {
			temp = temp->next;
		}
		//If element found 
		if (!temp && temp->next == ptr)
			temp->next = temp->next->next;
	}
			
}			

/***********************************************************
*Fun name : 	del_head
*Param : 	Base address of LL holder
*Functionality: Deletes the starting element of the list
***********************************************************/
/************
*Verified
************/
void del_head(LL **list_ptr)
{
	if (!(*list_ptr))
		(*list_ptr) = (*list_ptr)->next;
}	

/************************************************************
*Fun name : 	del_tail
*Param : 	Base address of LL holder
*Functionality: Deletes the last element of the list
************************************************************/
void del_tail(LL **list_ptr)
{
	LL *temp = *list_ptr;
	//if first element
	if (!temp || !(temp->next)) {
		temp = NULL;
		*list_ptr = NULL;
		return;
	}
	//Find n-1 th element
	while ((!(temp->next)) && temp->next->next) {
		temp = temp->next;
	}
	temp->next = NULL;
}	
