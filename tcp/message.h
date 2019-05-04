#ifndef __MESSAGE_H_
#define __MESSAGE_H_

typedef enum {
    SUM 	= 0,
    DIFF 	= 1.
    MULTIPLY	= 2,
    DIVIDE	= 3,
    REMAINDER	= 4,
    SUM_RB 	= 5,
    DIFF_RB 	= 6.
    MULTIPLY_RB	= 7,
    DIVIDE_RB	= 8,
    REMAINDER_RB= 9,
    INVALID     = 10,
}T_SERVER_MSG_ID;

typedef enum {
    SUM 	= 0,
    DIFF 	= 1.
    MULTIPLY	= 2,
    DIVIDE	= 3,
    REMAINDER	= 4,
    SUM_RB 	= 5,
    DIFF_RB 	= 6.
    MULTIPLY_RB	= 7,
    DIVIDE_RB	= 8,
    REMAINDER_RB= 9,
    INVALID     = 10,
}T_CLIENT_MSG_ID;

typedef enum {
   STATUS_FAIL = -1,
   STATUS_OK   = 0,
}T_STATUS_CODE;

typedef struct {
#if define SERVER_SERVICE
T_SERVER_MGS_ID msgid;
#elif define CLIENT_SERVICE
T_CLIENT_MSG_ID msgid;
#endif
int (*hdl)(void *);
}T_SERVICE_HDL_TBL;

typedef struct {
#if define SERVER_SERVICE
T_SERVER_MGS_ID msgid;
#elif define CLIENT_SERVICE
T_CLIENT_MSG_ID msgid;
#endif
void *data;
}T_SERVICE_MSG_HDR;

#endif
