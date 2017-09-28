/*  A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 */

#include <stdlib.h>

static int *func();

int main()
{
    int *pint = NULL;
    pint = func();
    printf("Value returned by func: %d",*pint);
    return 0;
}
static int *func()
{
    int a = 10;
    /* Splint should catch the fact that the address of 'a' which  
     * is allocated on the stack is being returned to the calling 
     * function
     */
    return &a;
}
