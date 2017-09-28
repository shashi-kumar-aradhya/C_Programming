/*****************************************************************************
 * File :  receive_process.c
 * Description : This file contains the functions for receiving data from 
 * another process using UDP sockets and displaying that data
 * 
 *****************************************************************************/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/msg.h>

static int message_cnt;

return_et receive_data(int msgqid, info_st *p_info);
return_et display_info(info_st * p_info);
int create_msgq();
 /****************************************************************************
 * Function : main
 * Description: This function is the entry point of this process and calls
 * the functions to accept data from the socket and display the message  
 *****************************************************************************/

 int main()
 {
     int msgqid; /* This will hold the identifier of the message queue */ 
     /* Create a variable of type info_st */
	 info_st *p_info = (info_st *) malloc (sizeof(info_st));

     if (NULL == p_info)
	 {
	    printf("Error in memory allocation\n");
		exit (1);
	 }
	 /* Create the message queue */
	 msgqid = create_msgq();

     while (1)
	 {
	   /* Receive data from the message queue */
	   if (FAILURE == receive_data(msgqid, p_info))
	      exit (1);
	 
	   /* Display the data */
	   else if (FAILURE == display_info(p_info))
	      exit (1);
	  }	   

	 return 0;
 }

 return_et receive_data(int msgqid, info_st *p_info)
 {
     msg_st buf;
     int junk=0;

     if (msgrcv(msgqid,(msg_st *)&buf, sizeof(buf), 0, 0) == -1 ){
	     perror("msgrcv");
		 return FAILURE;
	 }
	 else {
	     p_info = memcpy (p_info, &(buf.data), sizeof(info_st));
		 message_cnt++;
		 return SUCCESS;
	 }

 }

 return_et display_info(info_st * p_info)
 {
     printf ("\nMessage %d",message_cnt);
     if (p_info->bit_flag & NAME_PRESENT)
	 {
	     printf ("\nEmployee Name Present\n");
		 printf ("Name: %s", p_info->name);
	 }
     if (p_info->bit_flag & EMP_ID_PRESENT)
	 {
	     printf ("\nEmployee Id Present\n");
		 printf ("Emp Id: %s", p_info->emp_id);
	 }
     if (p_info->bit_flag & EXTN_PRESENT)
	 {
	     printf ("\nExtension Present\n");
		 printf ("Extn: %s", p_info->extn);
	 }
	 return SUCCESS;
 }

 int create_msgq()
 {
     int msgqid;
	 key_t key;

	 if ((key = ftok("send_process.c", 'B')) == -1) {  /* same key as send_process.c */
	     perror("ftok");
		 exit(1);
	 }

	 if ((msgqid = msgget(key, 0644)) == -1) { /* connect to the queue */
	     perror("msgget");
		 exit(1);
	 }

	 printf ("Receive Process: Ready\n");
	 printf ("Message Queue id: %d\n", msgqid);

	 return msgqid;
 }

	 
