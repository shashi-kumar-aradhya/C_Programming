/**********************************************************************
*File Name - WFREQ_utility.c
Purpose - Implementation some utility functions like reading an array of
pointers to strings, freeing memory etc.
***********************************************************************/

#include "WFREQ_header.h"

/**********************************************************************
*Function Name:read_string_array
*Description - Prints the contents of "array of pointers to characters"
*Arguments - The string array.
*Returns - Nothing
**********************************************************************/
void read_string_array(char** array)
{
  int ctrstrings = 0;
  while(*array != NULL)
  {
                printf("%s\n", *array);
                array++;
                ctrstrings++;
  }
  printf("Total Number of strings  = %d\n", ctrstrings);
}

/**********************************************************************
*Function Name:free_all_memory
*Description - Frees all memory of a string array, build using
"pointer to an array" of "pointer to characters"
*Arguments - The array to be freed.
*Returns - Nothing
**********************************************************************/
void free_all_memory(char** array)
{
  /*Free memory for all the strings and then the array itself*/
  char **temp = array;
  if (array != NULL)
  {
    while(*array != NULL)
    {
        free(*array);
        array++;
    }
    free(temp);
  }
}
/**********************************************************************
*Function Name:free_hashtable
*Description - Frees all memory, used by the hashnodes.
*Arguments - @hashtable - The hashtable, which is an array of pointers
to hasnodes.
*Returns - Nothing
**********************************************************************/
void free_hashtable(HASHNODE *hashtable[])
{
  HASHNODE *curptr, *nextptr;
  int index;

  /*We need to traverse the hash table to find non empty slots*/
  for (index = 0; index < BUCKETSIZE; index++)
  {
      /*If this slot is used, then only we need to free the node(s)*/
      if (hashtable[index] != NULL)
      {
          curptr = hashtable[index];
          while (curptr != NULL)
          {
             nextptr = curptr->next;
             free(curptr->word);
             free(curptr);
             curptr = nextptr;
          }
      }

  }
}


