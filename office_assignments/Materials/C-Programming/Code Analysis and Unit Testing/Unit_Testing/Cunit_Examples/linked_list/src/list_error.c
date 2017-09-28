#include <stdio.h>
#include "mylist.h"

/********************************************************************
*      			Global variables
********************************************************************/
int g_error_level = ERROR_MAJOR;

char *g_error_code_to_str[] = 
{
  "Unexpected End of File", 	//ERROR_UNEXPECTED_EOF
  "Invalid Character" 		//ERROR_INVALID_CHAR
  "Memory Failure",            // ERROR_MEMORY_FAILURE 
  "Invalid Input"               // ERROR_INVALID_INPUT 
};

/********************************************************************
*
* FUNCTION NAME: list_error
*
* DESCRIPTION: Prints the error message along with the error number
*
* RETURNS: Returns void
*********************************************************************/
void list_error(int err_level,
               int err_code)
{
    /* compare the err_level parameter against the global flag to see
       whether the input error level is suppressed or not. If not then
       the input error message is printed */

    if (err_level <= g_error_level)
    {
        printf("Error : (%s)\n", g_error_code_to_str[err_code]);
    }
}

