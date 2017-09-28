#ifndef PROJ_LL_H
#define PROJ_LL_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /*trace levels  */
    #define NO_TRACE       1
    #define BRIEF_TRACE    2
    #define DETAILED_TRACE 3


    #ifdef TRACE_FEATURE
 	#define A_TRACE(level, x)  if (g_trace_level >= level) printf x
    #else
 	#define A_TRACE(level, x) /* no definition */
    #endif

    /*One external declaration needed for setting the trace levels*/
    extern int g_trace_level;

    /* error details */
    #define ERROR_NONE     1
    #define ERROR_CRITICAL 2
    #define ERROR_MAJOR    3
    #define ERROR_MINOR    4

    /* list_error is defined in list_error.c */
    #define A_ERROR(err_level, err_code) list_error(err_level, err_code)

    /* Error Codes */
    #define ERROR_UNEXPECTED_EOF  0
    #define ERROR_INVALID_CHAR    1
    #define ERROR_MEMORY_FAILURE  2
    #define ERROR_INVALID_INPUT   3

    //declare the structure 
    struct mynode
    {
        char *name;
        int value;
        struct mynode *next;
    };

    //create a new type
    typedef struct mynode MYNODE;

    //function prototypes

    MYNODE *create_new_item(char *name, int value);
    MYNODE *add_at_front(MYNODE *listp, MYNODE *newp);
    MYNODE *add_at_last(MYNODE *listp, MYNODE *newp);
    void print_list(MYNODE *listp);
    void freeall(MYNODE *listp);
    MYNODE *lookup(MYNODE *listp, char *name);
    MYNODE *del_first_item(MYNODE *listp, char *name);
    MYNODE *copy_list(MYNODE *srcp);
    
    //function prototype for functions related to tracing
    void set_trace_flag(int trace_val);

    //function prototype for functions related to error handling
    void list_error(int err_level, int err_code);


#endif
