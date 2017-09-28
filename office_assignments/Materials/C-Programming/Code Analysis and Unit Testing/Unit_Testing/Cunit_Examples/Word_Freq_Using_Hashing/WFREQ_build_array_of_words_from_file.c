/***********************************************************************
Filename:WFREQ_build_array_of_words_from_file.c

*Purpose  -Implements a function to read a file pointed by a file pointer
*argument.It builds an array of pointers to individual words.

************************************************************************/

#include "WFREQ_header.h"

/****************************************************************************
*Function Name - read_words_from_file

*Description - Reads a file, pointed by the file pointer fp and returns the
words in an array of character pointers, simulated by a char **.

*Arguments - @fp - pointer to a file and @no_of_words which is a
variable to hold the number of words (may be 0 for an empty file)
or a negative value (-1) to indicate error.

*Returns - An array of pointers to words.Last element of the array is
NULL.
In case of an empty file the return value points to an one element array
containing NULL.
In case of an error  NULL is returned and the variable pointed by no_of_words
is set to negative (-1).
****************************************************************************/

char** read_words_from_file(FILE* fp, int  *no_of_words)
{
  char *wordptr ;
  char **buffer = NULL;
  char **tempbuffer = NULL;
  int wordcount = 0;
  int ret = 0;
  int error_flag = 0;
  char word[LINE_MAX];
  *no_of_words = 0;

  while (1)
  {
        wordptr = NULL;
        /*storing word in array word*/
        ret = fscanf(fp, "%s", word);
        if (EOF == ret)
        {
            if (feof(fp))
            {
                break;
            }
            else //For error
            {
                error_flag = 1;
                break;
            }
        }

        wordcount++;
        /*Now allocate an array to store the address of this word*/
        tempbuffer = realloc(buffer, wordcount * sizeof(char*));
        if (NULL == tempbuffer)
        {
            error_flag = 1;
            break;
        }
        /*Update buffer*/
        buffer = tempbuffer;
        tempbuffer = NULL;
        /*Allocate storage for this word*/
        wordptr = strdup(word);
        if (NULL == wordptr)
        {
            error_flag = 1;
            break;
        }
        else
        {
            /*update the array buffer with address of word*/
            *(buffer + (wordcount - 1) ) = wordptr;
        }
  }

    /* For adding the NULL at the end of the array of words reallocate, one more cell*/
   tempbuffer = realloc(buffer, (wordcount + 1) * sizeof(char*));
   if (NULL == tempbuffer)
   {
            /*Free all previously allocated memory*/
        error_flag = 1;
   }
   if (error_flag)
   {
        free_all_memory(buffer);
        *no_of_words = -1;
        return NULL;
   }
   else
   {

        buffer = tempbuffer;
        tempbuffer = NULL;
        *(buffer + wordcount ) = NULL;
        /*update variable no_of_words, which can be tested by the caller*/
        *no_of_words = wordcount;
        return buffer;
    }
}

