struct thread_struct {
	int count;
        struct {
                int op;
                union {
                        struct {
                                int pid;
                        } fork, exec;
                        struct {
                                int (*proc)(void *);
                                void *arg;
                        } thread;
                        struct {
                                void (*proc)(void *);
                                void *arg;
                        } cb;
                } u;
        } request;
};

