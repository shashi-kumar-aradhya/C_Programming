/******************************************************************************
* File Name:WFREQ_Test.c
* Purpose: Main function for unit testing of hashing framework
* ARICENT - Copyright (C) 2012 Aricent Inc . All Rights Reserved.
*******************************************************************************/

#include <stdio.h>
#include"WFREQ_header.h"
#include <string.h>
#include <sys/types.h>
#include <CUnit/Headers/Basic.h>
#include "WFREQ_Test.h"

/******************************************************************************
 *  Function     : initrlctxprocess_timer
 *   Description  : Initializes the suite
 *    Input        : Nothing
 *     Output       : int
 *     ***************************************************************************/
int init_hash(void)
{
    return 0;
}

/******************************************************************************
 *  Function     : cleanrlctxprocess_timer
 *   Description  : clean the suite after successful run
 *    Input        : Nothing
 *     Output       : int
 *     ***************************************************************************/
int clean_hash(void)
{
    return 0;
}

/*************************************************************************************
* Function     : main
* Description  :This is the main entry function for CUNIT Test Cases
* Input        :
* Output       : Int
************************************************************************************/
int main(int argc, char* argv[])
{
 CU_pSuite pSuite = NULL;

/* Adding suite */
   if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

    pSuite = CU_add_suite("LINKED LIST SUITE",init_hash,
            clean_hash);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if(
	(NULL == CU_add_test(pSuite,"WFREQ_myhash_ID_1",WFREQ_myhash_ID_1))||
	(NULL == CU_add_test(pSuite,"WFREQ_add_inc_word_in_hashtbl_ID_1",WFREQ_add_inc_word_in_hashtbl_ID_1))||
 	(NULL == CU_add_test(pSuite,"WFREQ_free_hashtable_ID_1",WFREQ_free_hashtable_ID_1))
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
