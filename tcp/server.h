
#ifndef __SERVER_H_
#define __SERVER_H_
#include "message.h"

/* Local definitions */
T_STATUS_CODE server_sum_hdl (void *);
T_STATUS_CODE server_sum_hdl_rb (void *);

T_STATUS_CODE server_diff_hdl (void *);
T_STATUS_CODE server_diff_hdl_rb (void *);

T_STATUS_CODE server_multiply_hdl (void *);
T_STATUS_CODE server_multiply_hdl_rb (void *);

T_STATUS_CODE server_divide_hdl (void *);
T_STATUS_CODE server_divide_hdl_rb (void *);

T_STATUS_CODE server_remainder_hdl (void *);
T_STATUS_CODE server_remainder_hdl_rb (void *);
#endif

