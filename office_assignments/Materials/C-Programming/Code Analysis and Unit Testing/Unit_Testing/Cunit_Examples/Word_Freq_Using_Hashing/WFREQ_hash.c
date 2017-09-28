/**********************************************************************
Filename - WFREQ_hash.c
Purpose - Implementation of the has function and the implementation of
adding an element or increasing the count of an element in the hash table
***********************************************************************/

#include "WFREQ_header.h"

/**********************************************************************
*Function Name:myhash
*Description - Generates a hashvalue corresponping to a string
*Arguments - The string which is to be hashed.
*Returns - The hashvalue
**********************************************************************/

unsigned int myhash(char *word)
{
	unsigned int hash_val = 0;
	while (*word)
	{
		hash_val = MULTIPLIER * hash_val + *word;
		word++;
	}
	return hash_val % BUCKETSIZE;
}

/**********************************************************************
*Function Name: add_inc_word_in_hashtable
*Description - Adds a new word in the hash table or increments the count
of an existing word.
*Arguments - @word - the word to be added, @hashtable - The hastable, which
is an array of "pointers" to HASHNODE. Each element of this array can point to
a list of nodes(HASHNODE). Each node is a "distinct string",  having a count
of number of occurences. When new nodes are added, they are added at front
of the existing list.
*Returns - -1, if any error has occured else 0.
**********************************************************************/

int add_inc_word_in_hashtbl(char *word, HASHNODE *hashtable[])
{
	unsigned int hash_val;
	HASHNODE *ptr;

	/*get the slot of the has table*/
	hash_val = myhash(word);

	/*if word is already added, then increment its count*/
	for (ptr = hashtable[hash_val]; ptr != NULL; ptr = ptr->next)
	{
		if (strcmp(word, ptr->word) == 0)
		{
			(ptr->count)++;
			return SUCCESS;
		}
	}

	/*If the word is not found, then it needs to be added*/
	ptr = malloc(sizeof *ptr);
	if (NULL == ptr)
	{
		fprintf(stderr, "Memory allocation failed in function add_inc_word_in_hashtable\n");
		return FAILURE;
	}
	ptr->count = 1;
	/*Add the word, by duplicating it*/
	ptr->word = strdup(word);
	if (NULL == ptr->word)
	{

		fprintf(stderr, "Memory allocation failed in function add_inc_word_in_hashtable\n");
		return FAILURE;
	}

	/*Add in front of the list of words corresponsing to that hashvalue*/
	ptr->next = hashtable[hash_val];
	hashtable[hash_val] = ptr;

	return SUCCESS;
}


