/******************************************************************************
* File Name:llTestmain.c
* Purpose: Main function to call the CUNIT Framework
* ARICENT - Copyright (C) 2012 Aricent Inc . All Rights Reserved.
*******************************************************************************/

#include <stdio.h>
#include "mylist.h"
#include "linked_list_Test.h"
#include <string.h>
#include <sys/types.h>
#include <CUnit/Headers/Basic.h>
int g_test = 0;

/******************************************************************************
 Function     : initrlctxprocess_timer
 Description  : Initializes the suite
 Input        : Nothing
 Output       : int
***************************************************************************/
int init_linkedlist(void)
{
    return 0;
}

/******************************************************************************
 Function     : cleanrlctxprocess_timer
 Description  : clean the suite after successful run
 Input        : Nothing
 Output       : int
***************************************************************************/
int cleanlinkedlist(void)
{
    return 0;
}

/*************************************************************************************
 Function     : main
 Description  :This is the main function for 
 Input        : 
 Output       : Int
************************************************************************************/

int main(int argc, char *argv[])
{
    CU_pSuite pSuite = NULL;

/* Adding suite */
   if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

    pSuite = CU_add_suite("LINKED LIST SUITE",init_linkedlist,
            cleanlinkedlist);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if(NULL == CU_add_test(pSuite,"Mylistfunction_create_new_item_ID_2",Mylistfunction_create_new_item_ID_2))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
    if(NULL == CU_add_test(pSuite,"Mylistfunction_create_new_item_ID_3",Mylistfunction_create_new_item_ID_3))
    {
	CU_cleanup_registry();
        return CU_get_error();
    }

    if((NULL == CU_add_test(pSuite,"Mylistfunction_create_new_item_ID_1",Mylistfunction_create_new_item_ID_1))||
       (NULL == CU_add_test(pSuite,"Mylistfunction_add_at_last_ID_1",Mylistfunction_add_at_last_ID_1)) ||
       (NULL == CU_add_test(pSuite,"Mylistfunction_add_at_front_ID_2",Mylistfunction_add_at_front_ID_2))||
       (NULL == CU_add_test(pSuite,"Mylistfunction_lookup_ID_1",Mylistfunction_lookup_ID_1))||
       (NULL == CU_add_test(pSuite,"Mylistfunction_add_at_front_ID_1",Mylistfunction_add_at_front_ID_1))
      )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry(); 
    
    return CU_get_error();
}
