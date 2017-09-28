/*****************************************************************************
 * File : send_process.c
 * Description : This file contains the functions for sending user input to 
 * another process using message queues
 * 
 *****************************************************************************/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>

/* Function prototypes */
return_et take_user_input(info_st *p_info, int msgqid);
return_et send_info(int msgqid, info_st* p_info);

 /****************************************************************************
 * Function : main
 * Description: This function is the entry point of this process and calls
 * the functions to take user input and send the message to the receiving 
 * process
 *****************************************************************************/

 int main()
 {
     int msgqid; /* This will hold the identifier of the message queue */
	 
     /* Create a variable of type info_st and initialize */
	 info_st *p_info = (info_st *) malloc (sizeof(info_st));

	 /* Initialize the bit_flag */
	 p_info->bit_flag = 0;

     if (NULL == p_info)
	 {
	    printf("Error in memory allocation\n");
		exit (1);
	 }
     /* Create the message queue */
	 msgqid = create_msgq();
    
	 while (1)
	 {
	     /* Insert data in the structure based on user input */
	     if (FAILURE == take_user_input(p_info, msgqid))
		    exit (1);
	 
	    /* Send the data to the receiving process */
	     else if (FAILURE == send_info(msgqid, p_info))
		    exit (1);
   	 }
     return  0;
 }

 /****************************************************************************
 * Function : take_user_input
 * Description: This function takes the user input and fills the structure
 * passed as argument. If the user presses n for "Wish to continue(y/n)"
 * the message queue will be deleted and the process will terminate
 * 
 *****************************************************************************/
 return_et take_user_input(info_st *p_info, int msgqid)
 {
	 char choice = '\0';

	 printf ("\nWish to continue(y/n):");
         fflush(stdin);
	 choice = getchar();
	 if ('n' == choice || 'N' == choice){
	     /* Remove the message queue */
		 if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
		         perror("msgctl");
				 exit (1);
	     }
		 else{
		   printf ("Message Queue id : %d  removed\n",msgqid);
		   exit (0);
		 }  
	 }	 

     getchar (); /*remove the \n in the buffer */
     printf("\nWish to enter name(y/n) :");
     fflush(stdin);
     choice = getchar(); 
     getchar (); /*remove the \n in the buffer */
     if ('y' == choice || 'Y' == choice){
	     printf ("Enter Name: ");
	     fgets(p_info->name, MAX_LEN, stdin);
	     p_info->bit_flag |= NAME_PRESENT;
     }
	     
     printf("\nWish to enter emp id(y/n) :");
     fflush(stdin);
     choice = getchar();
     getchar (); /*remove the \n in the buffer */
     if ('y' == choice || 'Y' == choice){
	     printf ("Enter Emp id: ");
	     fgets(p_info->emp_id, MAX_LEN, stdin);
	     p_info->bit_flag |= EMP_ID_PRESENT;
     }

     printf("\nWish to enter extension(y/n) :");
     fflush(stdin);
     choice = getchar();
     getchar (); /*remove the \n in the buffer */
     if ('y' == choice || 'Y' == choice){
	     printf ("Enter Extension: ");
	     fgets(p_info->extn, MAX_LEN, stdin);
	     p_info->bit_flag |= EXTN_PRESENT;
     }

     return SUCCESS;
 }

 /****************************************************************************
 * Function : send_info
 * Description: This function sends the data on the message queue
 *****************************************************************************/
 return_et send_info(int msgqid, info_st* p_info)
 {
	 msg_st buf;
	 buf.mtype = 1; /*This vaue is irrelevant in this scenario*/
	 memcpy (&(buf.data),p_info, sizeof(info_st));
	 if (msgsnd(msgqid, (msg_st *)&buf, sizeof(buf), 0) == -1){
		 perror("msgsnd");
		 return FAILURE;
	 }
	 else return SUCCESS;
 }


 /****************************************************************************
 * Function : create_msgq
 * Description: This function is the entry point of this process and calls
 * the functions to take user input and send the message to the receiving 
 * process
 *****************************************************************************/
 int create_msgq()
 { 
      int msgqid ;
      key_t key;
	  
      if ((key = ftok("send_process.c", 'B')) == -1){
	      perror("ftok");
		  exit(1);
	  }

	  if ((msgqid = msgget(key, 0644 | IPC_CREAT)) == -1){
	      perror("msgget");
		  exit(1);
	  }
	  printf ("Send Process: Ready\n");
	  printf ("Message Queue id: %d\n", msgqid);
	  return msgqid;
 }
