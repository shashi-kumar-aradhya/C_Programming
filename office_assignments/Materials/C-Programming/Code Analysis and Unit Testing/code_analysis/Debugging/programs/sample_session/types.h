/*****************************************************************************
 * File : types.h
 * Description : This file contains the type definitions
 * 
 *****************************************************************************/

/* Maximum length of any string */
#define MAX_LEN 10

/* This structure contains some personal information given by the user.
 * None of the fields are mandatory 
 * The bit_flag indicates which all fields are populated 
 */
typedef struct {
     unsigned int bit_flag;
	 char name[MAX_LEN];
	 char emp_id[MAX_LEN];
	 char extn[MAX_LEN];
} info_st;

#define NAME_PRESENT 0x0001
#define EMP_ID_PRESENT 0x0010
#define EXTN_PRESENT 0x0100

/* This enum defines the return types of functions */
typedef enum {
	FAILURE,
	SUCCESS
} return_et;

/* This structure defines the type of data to be sent on the message queue */
typedef struct {
	long mtype;
	info_st data;
}msg_st;
