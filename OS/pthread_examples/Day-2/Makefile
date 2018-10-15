# Compiler/Linker
CC = gcc
LD = gcc

# compiler/linker flags
CFLAGS = -g -Wall
LDFLAGS = -g

# files removal
RM = /bin/rm -f

# library to use when linking the main program
LIBS = -lpthread

# program's object files
PROG_OBJS = handler_thread.o handler_threads_pool.o main.o requests_queue.o

# program's executable
PROG = thread-pool-server.exe

# top-level rule
all: $(PROG)
	rm -rf xtree.txt xtree_helgrind.txt
$(PROG): $(PROG_OBJS)
	$(LD) $(LDFLAGS) $(PROG_OBJS) $(LIBS) -o $(PROG)

# compile C source files into object files.
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# clean everything
clean:
	$(RM) $(PROG_OBJS) $(PROG)

memcheck :
	valgrind --leak-check=yes --show-reachable=yes --vgdb=full --xtree-memory=full --xtree-memory-file=xtree.txt --log-file=valgrind.txt ./$(PROG)
helgrind:
	valgrind --tool=helgrind --vgdb=full --read-var-info=yes --xtree-memory=full --xtree-memory-file=xtree_helgrind.txt --log-file=helgrind.txt ./$(PROG)
callgrind:
	valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes --log-file=callgrind.txt ./$(PROG)

