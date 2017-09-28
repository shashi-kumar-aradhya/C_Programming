#ifndef PROJ_WORD_FREQ_USING_HASHING
#define PROJ_WORD_FREQ_USING_HASHING


    #include <stdio.h>
    #include <limits.h>
    #include <stdlib.h>
    #include <string.h>

    #define SUCCESS 0
    #define FAILURE -1
    #ifndef LINE_MAX
        #define LINE_MAX 2048
    #endif
    /*hash table related constants*/

    #define BUCKETSIZE 30000
    #define MULTIPLIER 31


    //declare the structure
    struct hashnode
    {
        char *word;
        int count;
        struct hashnode *next;
    };

    /*create a new type*/
    typedef struct hashnode  HASHNODE;

    /*function prototypes*/
    unsigned int myhash(char *word);
    int add_inc_word_in_hashtbl(char *word, HASHNODE *hashtable[]);
    void free_hashtable(HASHNODE *hashtable[]);
    char **read_words_from_file(FILE* fp, int  *no_of_words);
    void read_string_array(char** array);
    void free_all_memory(char** array);

#endif

