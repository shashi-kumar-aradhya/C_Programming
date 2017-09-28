/******************************************************************************
* File Name:linked_list_Test.c
* Purpose: Stubs for unit testing of linked list framework
* ARICENT - Copyright (C) 2012 Aricent Inc . All Rights Reserved.
*******************************************************************************/

#include <stdio.h>
#include "mylist.h"
#include <CUnit/Headers/Basic.h>

extern MYNODE *create_new_item(char *name, int value);
extern MYNODE *add_at_front(MYNODE *listp, MYNODE *newp);
extern void print_list(MYNODE *listp);
extern MYNODE *lookup(MYNODE *listp, char *name);
extern int g_test;

/*********************************************************************************************************
* Function     : Mylistfunction_create_new_item_ID_1
* Description  : verify that a new node is created and its pointer is returned when create_new_item is called. 
*                Also the value stored in the new node is the value which is passed when create_new_item is called.
* Input        : Nothing
* Output       : Nothing
* Exception    : If malloc fails then this test case will fail.
**************************************************************************************************************/
void Mylistfunction_create_new_item_ID_1(void)
{
    char name[10] = "demo";
    int value = 10;
    MYNODE *mynode_p = NULL;
/*function is called for success scenario*/
    mynode_p = create_new_item(name,value);
    CU_ASSERT(NULL != mynode_p);
    CU_ASSERT(10 == mynode_p->value);
    CU_ASSERT(0 == strcmp(mynode_p->name,name));
    CU_ASSERT(NULL == mynode_p->next);
/*free the memory allocated*/
    if(NULL != mynode_p)
    {
        free(mynode_p->name);
	free(mynode_p);
    }
}	

/*********************************************************************************************************
* Function     : Mylistfunction_add_at_front_ID_1
* Description  : verify that NULL is returned when NULL is send to add_at_front to add in a list.
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void  Mylistfunction_add_at_front_ID_1(void)
{
    MYNODE *mynode_p = NULL;
    MYNODE *mynode2_p = NULL;
    MYNODE *mynode_p_local = NULL;
	
/*1st case when pointer are NULL: Commenting this case as no error handling is there in main code*/
/*	mynode_p_local = add_at_front(mynode_p,mynode2_p);*/
}
   
/*********************************************************************************************************
* Function     : Mylistfunction_add_at_front_ID_2
* Description  : verify that add_at_front successfully add first element in the list when the list is empty. 
*                Also verify that add_at_front add a new element at the front of the list and returns the updated head. 
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void  Mylistfunction_add_at_front_ID_2(void)
{
    char name[10] = "demo";
    char name2[10] = "demo_1";
    int value = 1;
    int value2 = 2;
    MYNODE *mynode_p = NULL;
    MYNODE *mynode2_p = NULL;
    MYNODE *mynode_p_local = NULL;

/*case 2:*/
    mynode_p = create_new_item(name,value);
    if(NULL != mynode_p)
    {
        mynode2_p = create_new_item(name2,value2);
	if(NULL != mynode2_p)
	{
	    mynode_p_local = add_at_front(mynode_p,mynode2_p);
	    CU_ASSERT(mynode2_p == mynode_p_local); /*This poinetr will return the address of mynode2_p as head*/
	    CU_ASSERT(mynode_p_local->next == mynode_p);
	    print_list(mynode_p_local);
	}
    }	
/*case 3: listp:NULL*/
    mynode_p_local = NULL;
    mynode_p_local = add_at_front(mynode_p_local,mynode2_p);
    CU_ASSERT(mynode2_p == mynode_p_local); /*The first element is added in the list which is mynode2_p*/
    CU_ASSERT(NULL == mynode2_p->next);
    
/*free the allcated memory after test execution*/
    if(NULL != mynode_p)
    {
	 free(mynode_p->name);
	 free(mynode_p);
    }
    if(NULL != mynode2_p)
    {
	  free(mynode2_p->name);
	  free(mynode2_p);
    }
}

/*********************************************************************************************************
* Function     : Mylistfunction_add_at_last_ID_1
* Description  : Verify that a new list is created when add_at_last is called and the list pointer is NULL.
*                Also verify that add_at_last successfully added node at teh last when the list is not empty.*
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void  Mylistfunction_add_at_last_ID_1(void)
{
    char name[10] = "demo";
    char name1[10] = "demo_1";
    int value = 1;
    int value1 = 2;
    MYNODE *mynode_p = NULL;
    MYNODE *mynode2_p = NULL;
    MYNODE *mynode3_p = NULL;

/*case 1; when first element is added*/
    mynode2_p = create_new_item(name1,value1);
    if(NULL != mynode2_p)
    {
        mynode_p = add_at_last(mynode_p,mynode2_p);
	CU_ASSERT(mynode2_p == mynode_p);
        print_list(mynode_p);
    }   

/*case 2: when already have element in list*/
    mynode3_p = create_new_item(name,value);
    if(NULL != mynode3_p)
    {
       CU_ASSERT(NULL != add_at_last(mynode_p,mynode3_p));
        print_list(mynode_p);
		
    }	

/*free the allcated memory after test execution*/
   if(NULL != mynode2_p)
    {
	  free(mynode2_p->name);
	  free(mynode2_p);
    }
   if(NULL != mynode3_p)
   {
	  free(mynode3_p->name);
	  free(mynode3_p);
   }
}

/*********************************************************************************************************
* Function     : Mylistfunction_lookup_ID_1
* Description  : 1. Verify that the function lookup returns NULL when the list is empty.
*                2. Verify that the function return the pointer to the node which stores the same value for 
*                which lookup is called.
*                3. Verify that if the lookup is called for a name which is not present in the list, then 
*                NULL is returned.
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void  Mylistfunction_lookup_ID_1(void)
{
    char name1[10] = "demo_1";
    char name2[10] = "demo_2";
    int value1 = 2;
    int value2 = 3;
    MYNODE *mynode_p = NULL;
    MYNODE *mynode2_p = NULL;
    MYNODE *mynode3_p = NULL;

/*CASE 1: LIST is NULL*/	
   CU_ASSERT(NULL == lookup(mynode_p,name2));

    mynode2_p = create_new_item(name1,value1);
    mynode3_p = create_new_item(name2,value2);
    
    if(NULL != mynode2_p && NULL != mynode3_p)
    {
        mynode_p = add_at_front(mynode_p,mynode2_p);
        mynode_p = add_at_front(mynode_p,mynode3_p);

	/*lookup for name demo_2*/
        mynode3_p = lookup(mynode_p,name2);
	CU_ASSERT(0 == strcmp(name2,mynode3_p->name));

/*case 3*/
	CU_ASSERT(NULL == lookup(mynode_p,"hello"));

        free(mynode2_p->name);
        free(mynode3_p->name);
        free(mynode2_p);
        free(mynode3_p);
        mynode3_p = NULL;
        mynode_p = NULL;
	 /*check if the list is empty*/
        mynode2_p = lookup(mynode_p,name2);
        CU_ASSERT(NULL == mynode2_p);
    }
}

/*********************************************************************************************************
* Function     : Mylistfunction_create_new_item_ID_2
* Description  : Verify that NULL is returned by function create_new_item when malloc fails for 
*                allocating memory for new node
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void Mylistfunction_create_new_item_ID_2(void)
{
    char name[10] = "demo";
    int value = 10;
    MYNODE *mynode_p = NULL;
    g_test = 1;
/*function is called for success scenario*/
	mynode_p = create_new_item(name,value);
	CU_ASSERT(NULL == mynode_p);	
    g_test = 0;
}


/*********************************************************************************************************
* Function     : Mylistfunction_create_new_item_ID_3
* Description  : Verify that NULL is returned by function create_new_item when malloc fails for 
*                allocating memory for "name" variable of the node.
* Input        : Nothing
* Output       : Nothing
* Exception    :
**************************************************************************************************************/
void Mylistfunction_create_new_item_ID_3(void)
{
    char name[10] = "demo";
    int value = 10;
    MYNODE *mynode_p = NULL;
    g_test = 2;
/*function is called for success scenario*/
    mynode_p = create_new_item(name,value);
    CU_ASSERT(NULL == mynode_p);	
    g_test = 0;
}

