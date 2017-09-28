/*************************************************************************************************
 *FILE NAME	:header.h
 DESCRIPTION	:this file contains all the required standard libraries and function prototypes
************************************************************************************************/

/************************************************************************************************
 * 						HEADER FILES
 * **********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glib.h>
#include<assert.h>
#include<errno.h>

/************************************************************************************************
 * 						MACROS
 * **********************************************************************************************/
#define FILE_NAME_SIZE		140
#define MAX_FILES		50
#define ZERO			0
#define MAX_CHARACTERS 		1000
/***********************************************************************************************
 * 					FUNCTION PROTOTYPES
 * *********************************************************************************************/

char *search_replace(char *source, char *search_str, char *replace_str);
int read_from_file(char *in_file_name,char *search_string, char *replace_string, char *out_file_name);
