
#include "message.h"

#if defined SERVER_SERVICE
#include "server.h"
#elif defined CLIENT_SERVICE
#include "client.h"
#endif

#if defined SERVER_SERVICE
typedef T_SERVER_MSiG_ID T_MSG_ID;
#define print_msg(...) do { printf("Server -> file : %s: funtion : %s line : %d", __FILE__, __func__, __LINE__); printf(__VA_ARGS__); printf("\n"); }while(0)

#elif defined CLIENT_SERVICE
typedef T_CLIENT_MSG_ID T_MSG_ID;
#define print_msg(...) do { printf("client -> file : %s: funtion : %s line : %d", __FILE__, __func__, __LINE__); printf(__VA_ARGS__); printf("\n"); }while(0)
#endif

/* Local Declarations */

typedef struct {
    int param1;
    int param2;
}T_SERVICE_PARAM;
 
typedef struct {
    long int param1;
}T_SERVICE_RETURN_PARAM;



static const T_SERVICE_HDL_TBL service_hdl_service [] = 
{
#if defined SERVER_SERVICE
  { SUM, 		server_sum_hdl 		},
  { DIFF, 		server_diff_hdl 	},
  { MULTIPLY, 		server_multiply_hdl 	},
  { DIVIDE, 		server_divide_hdl 	},
  { REMAINDER, 		server_remainder_hdl 	},

//Readbacks
  { SUM_RB, 		server_sum_hdl_rb	},
  { DIFF_RB, 		server_diff_hdl_rb 	},
  { MULTIPLY_RB,	server_multiply_hdl_rb 	},
  { DIVIDE_RB, 		server_divide_hdl_rb 	},
  { REMAINDER_RB,	server_remainder_hdl_rb	},
  { INVALID,		NULL			};

#elif define CLIENT_SERVICE
  { SUM, 		client_sum_hdl 		},
  { DIFF, 		client_diff_hdl 	},
  { MULTIPLY, 		client_multiply_hdl 	},
  { DIVIIDE, 		client_divide_hdl 	},
  { REMAINDER, 		client_remainder_hdl 	},

//Readbaks
  { SUM_RB, 		client_sum_hdl_rb	},
  { DIFF_RB, 		client_diff_hdl_rb	},
  { MULTIPLY_RB, 	client_multiply_hdl_rb 	},
  { DIVIIDE_RB, 	client_divide_hdl_rb 	},
  { REMAINDER_RB, 	client_remainder_hdl_rb	},
  { INVALID,		NULL			};

#endif
};

void handler_exec(T_SERVICE_MSG_HDR *p_msg)
{
    int i = 0;
    T_STATUS_CODE status = STATUS_FAIL;
    T_SERVICE_HDL_TBL *p_tbl = NULL;
    int count = (sizeof(service_hdl_service)/sizeof(service_hdl_service[0]));
    for (i = 0; i < count; i++)
    {
       p_tbl = & service_hdl_service[i];
       if((p_msg != NULL) && ( p_tbl->msgid == p_msg->msgid) && (p_tbl->hdl != NULL))
       {
         status = p_tbl->hdl(p_msg);
         if(status != STATUS_OK)
         {
          print_msg("Error while handling message id = %d, error code = %d", p_tbl->msgid, status);
         }
	 else
	 {
          print_msg("handled message id = %d", p_tbl->msgid, status);
         }
       }
	//put this message to QUEUE
    }
}



