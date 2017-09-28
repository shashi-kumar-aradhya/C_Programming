/*  A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 *  This program takes some numbers from a given file. The file "numbers.in" 
 *  contains the count of numbers N in the first line followed by N lines
 *  each containing one number. The function find_max then finds the maximum
 *  of those numbers
 */

#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void take_input();
long find_max();

/* global variables */
long *ar; /* Dynamic Array containing the numbers */
int cnt; /* Count of numbers */

int main()
{
	long max=0;
    take_input();
	max = find_max();
	printf("The maximum number is %ld",max);
    return(0);

}
void take_input()
{
    int i;
    FILE *fp_in = fopen("./numbers.in","r");

    /* fopen is a function which may return NULL under error conditions
	   If the programmer does not check for the same, static analysis will
	   return an error */
	   
	fscanf(fp_in,"%d",&cnt);

	ar = (long *)malloc(sizeof(long)*cnt);
	
    /* malloc is a function which may return NULL under error conditions
	   If the programmer does not check for the same, static analysis will
	   return an error */
	   
	if (NULL == ar)
	{
	   printf("Memory cannot be allocated!\n");
	   exit(EXIT_FAILURE);
	}

	for (i=0; i < cnt; i++)
	{
	   fscanf(fp_in, "%ld",&ar[i]);
	}
	fclose(fp_in);
	return;
}
long find_max()
{
	int i=0;
	long max=ar[0];
	for (i=0; i < cnt; i++)
	{
	    if (ar[i] > max)
			max = ar[i];
	}
	/* The programmer has forgotten to return the value computed as maximum
	   Static analysis will point this out */
	
}
