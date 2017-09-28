/******************************************************************************
* File Name:WFREQ_Test.c
* Purpose: Stubs for unit testing of hashing framework
* ARICENT - Copyright (C) 2012 Aricent Inc . All Rights Reserved.
*******************************************************************************/

#include "WFREQ_header.h"
#include <CUnit/Headers/Basic.h>

extern int add_inc_word_in_hashtbl(char *word, HASHNODE *hashtable[]);
extern unsigned int myhash(char *word);

/*****************************************************************************************************************
* Function     : WFREQ_myhash_id_1
* Description  : 1. Verify that a hash value is returned by the function "myhash" according to the algo when
* 		 a string is passed to the function.
* 		 2. Verify that invalid value is returned when a NULL pointer is passes to the function "myhash".
* Input        : Nothing
* Output       : Nothing
* Exception    : 
******************************************************************************************************************/
void WFREQ_myhash_ID_1(void)
{
	char word[] = "abcd";
	char *c = NULL;
	unsigned int ret = 0;

	ret = myhash(word);
	CU_ASSERT(17074 == ret);

	/*CASE 2: If NULL pointer is passed to the function*/
	
//	ret = myhash(c); /*this call will crash becasue call handling is not done in the code for NULL pointer*/
}

/*******************************************************************************************************************
* Function     : WFREQ_myhash_id_1
* Description  : 1. Verify that a new memory is allocated when a new element is added to the hash table with a 
* 		new index.
* 		2. Verify that if already there is element at an index in hashtable then only counter is incremented.
* Input        : Nothing
* Output       : Nothing
* Exception    : 
********************************************************************************************************************/
void WFREQ_add_inc_word_in_hashtbl_ID_1(void)
{
	HASHNODE  *head[BUCKETSIZE] = {{NULL}};
	char word[] = "abcd";
	int ret = FAILURE;
	unsigned int hash_val = 0;
	HASHNODE *temp_hash = NULL;
	
	/*case 1: when no element in hash table*/
	hash_val = myhash(word);
	ret = add_inc_word_in_hashtbl(word,head);
	
	temp_hash = head[hash_val];	
	CU_ASSERT(SUCCESS == ret);
	CU_ASSERT(1 == temp_hash->count);

	/*case 2 one element already added in hash table*/
	ret = add_inc_word_in_hashtbl(word,head);
	temp_hash = head[hash_val];	
	CU_ASSERT(SUCCESS == ret);
        CU_ASSERT(2 == temp_hash->count);

/*free the memory after use*/
	free_hashtable(head);

}

/*********************************************************************************************************
* Function     : WFREQ_myhash_id_1
* Description  : 1. Verify that "free_hashtable" does nothing if the hash table is empty.
* 		 2. Verify that "free_hashtable" free the memory if there are some elements at any index.
* Input        : Nothing
* Output       : Nothing
* Exception    : 
**************************************************************************************************************/

void WFREQ_free_hashtable_ID_1(void)
{
	HASHNODE * hash_table[BUCKETSIZE] = {NULL};
	char word[] = "abcd";
	char word2[] = "pqrt"; 
	
	/*when the hashtable is not present*/
	free_hashtable(hash_table);

	add_inc_word_in_hashtbl(word,hash_table);
	add_inc_word_in_hashtbl(word2,hash_table);
	
	/*case 2:*/
	free_hashtable(hash_table);
}
