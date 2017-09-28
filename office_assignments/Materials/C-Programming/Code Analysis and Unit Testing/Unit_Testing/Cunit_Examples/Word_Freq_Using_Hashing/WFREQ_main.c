/**********************************************************************
*File Name:WFREQ__main.c
*Purpose -Accepts a file name through command line argument.
*It then prints the words and the frequency of those words.
**********************************************************************/

#include "WFREQ_header.h"

int main(int argc, char* argv[])
{
        FILE *fp = NULL;
        char** array_of_ptrs_to_words = NULL, **temp_ptr_to_words = NULL;
        int tot_num_of_words = 0;
        HASHNODE *hashptr = NULL, *hashtable[BUCKETSIZE] = {NULL};
        int retval = 0;
        int error_flag = 0;
        int index = 0;

        if (argc < 2)
        {
            printf("Usage: %s <filename>\n", argv[0]);
            return EXIT_FAILURE;
        }
        fp = fopen(argv[1], "r");
        if (NULL == fp)
        {
         fprintf(stderr, "File %s cannot be opened\n", argv[1]);
         return EXIT_FAILURE;
        }

        array_of_ptrs_to_words = read_words_from_file(fp, &tot_num_of_words);
        if (-1 == tot_num_of_words)
        {
            fprintf(stderr, "Error Occured during processing file : %s \n", argv[1]);
            return EXIT_FAILURE;
        }
        /*Save the address in a variable, so that it can be freed later*/
        temp_ptr_to_words = array_of_ptrs_to_words;

        while (*array_of_ptrs_to_words != NULL)
        {

	   /*Build the hash table here*/
      	   retval = add_inc_word_in_hashtbl(*array_of_ptrs_to_words, hashtable);
           if (FAILURE == retval)
           {
                error_flag = 1;
                break;
           }

           /*point to the next word*/
            array_of_ptrs_to_words++;
        }

        if (error_flag)
        {
            fprintf(stderr, "Error Occured during processing! Exiting with failure\n" );
            /*Now free all memory and exit with failure*/
            :wq!
free_hashtable(hashtable);
       	    free_all_memory(temp_ptr_to_words);
            return EXIT_SUCCESS;
        }
        else
        {
            /*print the hashtable*/
            for (index = 0; index < BUCKETSIZE; index++)
            {
                for (hashptr = hashtable[index]; hashptr != NULL; hashptr = hashptr->next)
                {
                    printf("%-50s %d\n", hashptr->word, hashptr->count);

                }
            }

            free_hashtable(hashtable);
            free_all_memory(temp_ptr_to_words);

            return SUCCESS;
        }

}

