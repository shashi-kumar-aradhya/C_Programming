#ifndef __CLIENT_H_
#define __CLIENT_H_
#include "message.h"

/* Local definitions */
T_STATUS_CODE client_sum_hdl (void *);
T_STATUS_CODE client_sum_hdl_rb (void *);

T_STATUS_CODE client_diff_hdl (void *);
T_STATUS_CODE client_diff_hdl_rb (void *);

T_STATUS_CODE client_multiply_hdl (void *);
T_STATUS_CODE client_multiply_hdl_rb (void *);

T_STATUS_CODE client_divide_hdl (void *);
T_STATUS_CODE client_divide_hdl_rb (void *);

T_STATUS_CODE client_remainder_hdl (void *);
T_STATUS_CODE client_remainder_hdl_rb (void *);
#endif

