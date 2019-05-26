#include <stdio.h>
#include <stdlib.h>
#include <linux/ipc.h>
#include <linux/msg.h>
struct mymsgbuf {
    long    mtype;          /* Message type */
    int     request;        /* Work request number */
    double  salary;         /* Employee's salary */
    double  test;
} msg;

int get_queue_ds( int qid, struct msgqid_ds *qbuf )
{
        if( msgctl( qid, IPC_STAT, qbuf) == -1)
        {
                return(-1);
        }
        
        return(0);
}

int change_queue_mode( int qid, char *mode )
{
        struct msqid_ds tmpbuf;

        /* Retrieve a current copy of the internal data structure */
        get_queue_ds( qid, &tmpbuf);

        /* Change the permissions using an old trick */
        sscanf(mode, "%ho", &tmpbuf.msg_perm.mode);

        /* Update the internal data structure */
        if( msgctl( qid, IPC_SET, &tmpbuf) == -1)
        {
                return(-1);
        }
        
        return(0);
}

int remove_queue( int qid )
{
        if( msgctl( qid, IPC_RMID, 0) == -1)
        {
                return(-1);
        }
        
        return(0);
}


int read_message( int qid, long type, struct mymsgbuf *qbuf )
{
        int     result, length;

        /* The length is essentially the size of the structure minus sizeof(mtype) */
        length = sizeof(struct mymsgbuf) - sizeof(long);        

        if((result = msgrcv( qid, qbuf, length, type,  0)) == -1)
        {
                return(-1);
        }
        
        return(result);
}

int open_queue( key_t keyval )
{
        int     qid;
        
        if((qid = msgget( keyval, IPC_CREAT | 0660 )) == -1)
        {
                return(-1);
        }
        
        return(qid);
}

int send_message( int qid, struct mymsgbuf *qbuf )
{
        int     result, length;

        /* The length is essentially the size of the structure minus sizeof(mtype) */
        length = sizeof(struct mymsgbuf) - sizeof(long);        

        if((result = msgsnd( qid, qbuf, length, 0)) == -1)
        {
                return(-1);
        }
        
        return(result);
}
int peek_message( int qid, long type )
{
        int     result, length;

        if((result = msgrcv( qid, NULL, 0, type,  IPC_NOWAIT)) == -1)
        {
//                if(errno == E2BIG)
                        return(-1);
        }
        
        return(result);
}

int main()
{
        int    qid;
        key_t  msgkey;

        /* Generate our IPC key value */
        msgkey = ftok(".", 'm');

        /* Open/create the queue */
        if(( qid = open_queue( msgkey)) == -1) {
                perror("open_queue");
                exit(1);
        }

        /* Load up the message with arbitrary test data */
        msg.mtype   = 1;        /* Message type must be a positive number! */   
        msg.request = 1;        /* Data element #1 */
        msg.salary  = 1000.00;  /* Data element #2 (my yearly salary!) */
        
        /* Bombs away! */
        if((send_message( qid, &msg )) == -1) {
                perror("send_message");
                exit(1);
        }

        if((read_message( qid, 1, &msg )) == -1) {
                perror("receive_message");
                exit(1);
        }

}
