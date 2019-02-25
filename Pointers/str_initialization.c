#include <stdio.h>


enum debug_obj_state {
        ODEBUG_STATE_NONE,
        ODEBUG_STATE_INIT,
        ODEBUG_STATE_INACTIVE,
        ODEBUG_STATE_ACTIVE,
        ODEBUG_STATE_DESTROYED,
        ODEBUG_STATE_NOTAVAILABLE,
        ODEBUG_STATE_MAX,
};
static const char *obj_states[ODEBUG_STATE_MAX] = {
        [ODEBUG_STATE_NONE]             = "none",
        [ODEBUG_STATE_INIT]             = "initialized",
        [ODEBUG_STATE_INACTIVE]         = "inactive",
        [ODEBUG_STATE_ACTIVE]           = "active",
        [ODEBUG_STATE_DESTROYED]        = "destroyed",
        [ODEBUG_STATE_NOTAVAILABLE]     = "not available",
};


int main()
{
	int i =0;
	for (i =0; i< ODEBUG_STATE_MAX; i++)
	printf("object = %d\tname = %s\n", i, obj_states[i]);   

	return 0;
}
