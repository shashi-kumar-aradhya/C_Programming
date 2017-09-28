/********************************************************************************************************************************
 * FILE NAME 	:func.c
 *
 * DESCRIPTION	:This file contains file operations and search and replace function
 * ******************************************************************************************************************************/

/********************************************************************************************************************************
 * 					HEADER FILES
 * ******************************************************************************************************************************/
#include<header.h>


/********************************************************************************************************************************
 * FUNCRION NAME:read_from_file
 *
 * DESCRIPTION	:This function reads lines from input file and writes the modified string to output file
 *
 * PARAMETERS	:Parameters are self descriptive.
 *
 * RETURNS	:Returns success or failure
 * *******************************************************************************************************************************/
int read_from_file(
		char *in_file_name,
		char *search_string, 
		char *replace_string, 
		char *out_file_name
		)
{
	FILE		*fp_in;
	FILE		*fp_out;
	GPtrArray*      output_lines = g_ptr_array_new();
    	GPtrArray*      input_lines = g_ptr_array_new();
	int		line_count=0;
	int		index;
	char		*source;
	char		*out_string;
	char		*buffer;
	int		buffer_index = 0;

	source = (char*)malloc(MAX_CHARACTERS * sizeof(char));
	if (NULL == source)
        {
                /*error in allocating memory*/
                printf("\nError while allocating memory!!");
                return (EXIT_FAILURE);
        }

	out_string = (char*)malloc(MAX_CHARACTERS * sizeof(char));
	if (NULL == out_string)
        {
                /*error in allocating memory*/
                printf("\nError while allocating memory!!");
                return (EXIT_FAILURE);
        }

	buffer = (char*)malloc(sizeof(char));
	if (NULL == buffer)
        {
                /*error in allocating memory*/
                printf("\nError while allocating memory!!");
                return (EXIT_FAILURE);
        }
	

	 /*open input file in read mode*/ 
 	fp_in = fopen(in_file_name, "r");
	
	if (NULL == fp_in)
        {
                /*error in opening input file in read mode*/
                printf("\nError while  opening  input file!!");
                return (EXIT_FAILURE);
        }
	
 	/*open output file in write mode*/
	fp_out = fopen(out_file_name, "w");
	if (NULL == fp_out)
        {
                /*error in allocating memory*/
                printf("\nError while allocating memory!!");
                return (EXIT_FAILURE);
        }


	/*read the first character from file*/
	char ch = fgetc(fp_in);
	int size = 0;
	while (1)
	{
		/*if end of file reached , break immediately*/
		if(feof(fp_in))break;
		
		if (ch == '\n')
		{	
			/*reached end of line */
			/*allocate memory for NULL charcter and store NULL*/
			buffer = realloc(buffer, (++size *sizeof(char)));
			buffer[buffer_index]= '\0';
			/*add the line to array of strings */
			g_ptr_array_add(input_lines,g_strdup(buffer));
			/*clear the buffer*/
			size_t len = strlen(buffer);
			memset(buffer,ZERO,len);
			/*increament the number of lines in a file*/
			line_count++;
			/*initialize the buffer index to 0*/
			buffer_index = 0;
			size = 0;
		}
		else
		{
			/*allocate memory for each character and store */
			buffer = realloc(buffer, (++size *sizeof(char)));
			buffer[buffer_index] = ch;
			/*increment the index of buffer*/			
			buffer_index++;	
		}
		/*read the next character*/
		ch = fgetc(fp_in);	
	}/*end of while loop*/


	for (index = 0; index < line_count; index++)
	{	
		/*
 		 *call search_replace function for each line 
		 */			
		/*access every line and store in source*/
		strcpy(source, g_ptr_array_index(input_lines, index));
		/*copy the modified string returned from search_replace function*/
		strcpy(out_string,search_replace(source,search_string,replace_string));
		/*copy the modified string in to array of pointers*/
		g_ptr_array_add(output_lines,g_strdup(out_string));
	}
	
	/*
 	 *copy the modified lines to output file
	 */
	for (index = 0;index < line_count;index++)
		fprintf(fp_out,"%s\n",(char*)g_ptr_array_index(output_lines,index));
	
	/*
 	 * close file pointers
 	 */
	fclose(fp_in);
	fclose(fp_out);
	/*
 	 * deallocate memory
 	 */
	free(source);
	free(buffer);
	free(out_string);
	/*deallocate each array of character */
	g_ptr_array_foreach(input_lines, (GFunc)g_free, NULL);
	/*free the pointer to array of strings*/
	g_ptr_array_free(input_lines, TRUE);
	/*deallocate each array of charaters */
	g_ptr_array_foreach(output_lines, (GFunc)g_free, NULL);
	/*free the pointer to array of strings*/
	g_ptr_array_free(output_lines, TRUE);

	return EXIT_SUCCESS;
}


/********************************************************************************************************************************
 * FUNCRION NAME:search_replace
 *
 * DESCRIPTION	:This function  searches for search string in each string and replaces it with replace string
 *
 * PARAMETERS	:Parameters are self descriptive.
 *
 * RETURNS	:modified string
 *
 * ******************************************************************************************************************************/
char *search_replace(
			char *source, 
			char *search_str, 
			char *replace_str
			)
{
    char	*newstr;
    char	*temp;
    char	*found_ptr;
    int		search_str_len;
    int		replace_str_len;
    int 	earlier_str_len;
    int 	new_str_len;
    int 	next_search_pos;

    /*
     * Initialise variables
     */
    earlier_str_len  = strlen(source);
    search_str_len = strlen(search_str);
    replace_str_len = strlen(replace_str);
    new_str_len = earlier_str_len;
    next_search_pos = 0;

    /*
     *Start with new string as duplicate of  the original string
     */  
    newstr = strdup(source);
    if (NULL == newstr)
    {
        fprintf(stderr, "Internal Error so Cannot proceed\n");
        return source;
    }

    /*
     * If the search pattern or the source string is an empty string,
     * return with the copy of  the original string
     */
    if ((0 == search_str_len) || (0 == earlier_str_len))
    {
        if (0 == search_str_len)
        {
            fprintf(stderr, "The string which you wanted to search is empty!\n");
        }
        else
        {
            fprintf(stderr, "The string which is to be searched is empty!\n");
        }
        return newstr;
    }


    while ((new_str_len - next_search_pos ) >= search_str_len)
    {
        /*
	 *strstr finds the first occurence of string within another string
	*/
        found_ptr = strstr(newstr + next_search_pos,  search_str);

        if (found_ptr != NULL)
        {
            /*
 	     * Calculate new length of the string - Unmatched part + replace_string + rest of the
 	     * string to be matched 
 	     */
 
            new_str_len  =  (found_ptr - newstr) +
                            replace_str_len +
                            (earlier_str_len - ((found_ptr - newstr) + search_str_len));

            /*
 	     * Allocate memory for the new updated string add 1 for string terminator
 	     */
            temp = calloc(new_str_len + 1, sizeof(char));
            if (NULL == temp)
            {
                fprintf(stderr, "Memory Allocation failed, while building new string\n");
                //return back the original source string
                return source;
            }


            /*
	     * Build the new string by copying the 1)Unmatched part 2)Replacement string
	     * 3)Portion, yet to be matched
	     */
            memcpy(temp, newstr, found_ptr - newstr);
            memcpy(temp + (found_ptr - newstr), replace_str, replace_str_len);
            memcpy(temp + (found_ptr - newstr) + replace_str_len, found_ptr + search_str_len,
            (earlier_str_len - ((found_ptr - newstr) + search_str_len)));

            /*
 	     * Now free the earlier string
 	     */
            free(newstr);
            /*
             * Update newstring which is now to be searched
             */
            newstr = temp;
           /*
 	    * remember earlier string length
 	    */
            earlier_str_len = new_str_len;
            /*
 	     * update next search position
 	     */
            next_search_pos = next_search_pos + replace_str_len;

        }
        else
        {
            //Failed to match- Break
            break;
        }
    }
	strcpy(source,newstr);
	free(newstr);
 return source;

}



