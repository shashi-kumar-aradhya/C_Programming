/****************************************************************************************************************************************
 * FILE NAME	:main.c
 *
 * DESCRIPTION	:Takes two strings through command line arguments. 
 *
 * 		One string is a search string and another string is the replacement string. 
 *
 * 		Reads input files and produce output files, in which the search string got replaced by  the replacement string
 * 		
 * 		If  the name of  the input file is input_1.txt the name of  the output file will be input_1.txt.out
 * 		(that is a new file got created with the string out appended to its name).
 *
 * 		There may be more than one input file and their names are kept in a config file (say config.txt),
 *
 * *************************************************************************************************************************************/

/************************************************************************************************************************************
 * 					HEADER FILES
 ************************************************************************************************************************************/
#include<header.h>

int main(int argc, char* argv[])
{
	char		*search_string;
	char		*replace_string;
	char		*filename;
	FILE		*fp_config;
	char 		*in_file_name;
	char		*out_file_name;
	GPtrArray*	in_file_names = g_ptr_array_new();
	GPtrArray* 	out_file_names = g_ptr_array_new();
	int		file_count;
	int		index;
	
	system("clear");

	/*checking command line arguements*/
	if (argc > 3 || argc < 3)
	{
		printf("\n*****************************************************\n");
		printf("Provide required number of arguements\n");
		printf("Arg1: string to search\nArg2: string to replace\n");
		printf("Program terminating !!\nRerun again.....");
		printf("\n*****************************************************\n");
		return EXIT_FAILURE;
	}

	size_t search_string_len, replace_string_len;
	search_string_len = (strlen(argv[1])+1) * sizeof(char);
	/*allocate memory to store the string to be searched*/
	search_string = (char *)malloc(search_string_len);
	
	/*error handling for search_string*/
	if (NULL != search_string)
	{	
		/*no error in allocating memory.. copy the string*/
		strcpy(search_string,argv[1]);
	}
	else
	{
		/*error in allocating memory*/
		printf("\nError while allocating memory !!");
		return (EXIT_FAILURE);
	}

	/*allocate memory to store the string to be replaced*/
	replace_string_len = (strlen(argv[2])+1) * sizeof(char);
	replace_string = (char *)malloc(replace_string_len);
	/*error handling for replace string */
	if (NULL != replace_string)
	{
		/* no error in allocating memory.. copy the string*/
		strcpy(replace_string,argv[2]);
	}
	else
	{
		/*error in allocating memory*/
		printf("\nError while allocating memory!!");
		return (EXIT_FAILURE);
	}
	
	/*allocating memory to store file name read from config.txt*/
	filename = (char *)malloc(FILE_NAME_SIZE * sizeof(char));
	if (NULL == filename)
	{	
		/*error in allocating memory*/
		printf("\nError while allocating memory!!");
		return (EXIT_FAILURE);
	
	}
	
	
	in_file_name = (char *)malloc(FILE_NAME_SIZE * sizeof(char));
	if (NULL == in_file_name)
	{	
		/*error in allocating memory*/
		printf("\nError while allocating memory!!");
		return (EXIT_FAILURE);
	}
	
	out_file_name = (char *)malloc(FILE_NAME_SIZE * sizeof(char));
	if (NULL == out_file_name)
	{	
		/*error in allocating memory*/
		printf("\nError while allocating memory!!");
		return (EXIT_FAILURE);
	}

	/*open config.txt file in read mode*/
	fp_config = fopen("config.txt","r");
	if (NULL == fp_config)
	{
		/*file opening failed*/
		perror("Error : config.txt cannot be opened in \"r\" mode");
		return EXIT_FAILURE;
	}
	
	file_count=0;/*variable holds the number of files*/

	/*read config.txt file and store it in array of strings*/
	while (EOF != fscanf(fp_config, "%s",filename))
	{	
		/*if end of file reached break immediately*/
		if(feof(fp_config))
			break;
		/*abort if filename length is more than 128*/
		assert(strlen(filename) <= 128);
		/*store the file names in array of strings*/
		g_ptr_array_add(in_file_names, g_strdup(filename));
		/*generate output file name by concatetnating ".out" to input file */
		strcat(filename,".out");
		/*store the output file name in array of strings*/
		g_ptr_array_add(out_file_names,g_strdup(filename));
		/*increment the file count*/
		file_count++;
	}/*end of while*/
	
	if(file_count > MAX_FILES)
	{	
		/*maximum number of files exceeded 50*/
		printf("\nNumber of files exceeded the maximum limit.");
		printf("\nnumber of files should be less than or equal to 50!!\n");
		return (EXIT_FAILURE);
	}
	

	/*
 	 *accessing each file and passing those as parameters to file operation function
 	 */ 
	for (index = ZERO; index < file_count; index++)
	{	
		/*copy the input file name to array of character*/
		strcpy(in_file_name,(char*) g_ptr_array_index(in_file_names, index));
		/*copy the output file name to array of character*/
		strcpy(out_file_name,(char *) g_ptr_array_index(out_file_names, index));
		
		if(EXIT_SUCCESS ==  read_from_file(in_file_name,search_string,replace_string,out_file_name))
		{
			printf("\nSuccessfully read from input file %s",in_file_name);	
		}
		else
		{
			printf("\nError in redaing input file %s", in_file_name);
			return (EXIT_FAILURE);	
		}

	}
	printf("\n");	
	/*close the file pointer*/
	fclose(fp_config);
	/*free all the allocated memory*/
	free(in_file_name);
	free(out_file_name);
	free(search_string);
	free(replace_string);
	free(filename);
	/*free memory for each string*/
	g_ptr_array_foreach(in_file_names, (GFunc)g_free, NULL);
	/*free pointer to array of strings*/
	g_ptr_array_free(in_file_names, TRUE);
	/*free memory for each string*/
	g_ptr_array_foreach(out_file_names, (GFunc)g_free, NULL);
	/*free the pointer to array of strings*/
	g_ptr_array_free(out_file_names, TRUE);
	
	return	EXIT_SUCCESS;
}


