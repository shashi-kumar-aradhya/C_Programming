/*  A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 *
 *  Reference:http://www.pdc.kth.se/training/Tutor/Basics/lint/index-frame.html 
 */

#include <stdio.h>

int main(int argv, char *argc[])
{
   /*
    * Splint should catch the fact that many variables are never used:
    *    argc, argv, b, c
    */
    int i = 1, j = 30, k = 5;
    long a = 10, b = -20 , c = 0;
    char ch = 'z';
    float z = 9.99;
    
   /*
    * Splint should catch the fact that the arguments to the + operator
    * are of different types. Also the left hand variable and right hand
    * value in the assignment are of different types
    */
    i = (double)(ch + ((double) j - z ));
    j = (float)(a + ch + z);

    return(0);

}
