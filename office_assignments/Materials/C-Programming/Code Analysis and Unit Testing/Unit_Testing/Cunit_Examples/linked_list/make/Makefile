CC = gcc
#used standard c99 where the __func__ is available to print function names
CFLAGS = -Wall -c -g -DTRACE_FEATURE -std=c99
OFLAGS = -o
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
BIN = ../bin/
INCLUDE = -I../include/
HEADER = ../include/
SRC = ../src/
OBJ = ../obj/

$(BIN)linked_list: $(OBJ)mylistmain.o $(OBJ)mylistfunctions.o $(OBJ)list_error.o
	$(CC) $(OFLAGS) linked_list $(OBJ)mylistmain.o $(OBJ)mylistfunctions.o $(OBJ)list_error.o
	mv linked_list $(BIN)

$(OBJ)mylistmain.o: $(SRC)mylistmain.c $(HEADER)mylist.h
	$(CC) $(CFLAGS) $(SRC)mylistmain.c $(INCLUDE)
	mv mylistmain.o $(OBJ)

$(OBJ)mylistfunctions.o: $(SRC)mylistfunctions.c $(HEADER)mylist.h
	$(CC) $(CFLAGS) $(SRC)mylistfunctions.c $(INCLUDE)
	mv mylistfunctions.o  $(OBJ)

$(OBJ)list_error.o: $(SRC)list_error.c $(HEADER)mylist.h
	$(CC) $(CFLAGS) $(SRC)list_error.c $(INCLUDE)
	mv list_error.o  $(OBJ)

valgrind: $(BIN)linked_list
	valgrind $(VFLAGS) ./$(BIN)linked_list

clean: 
	rm $(BIN)linked_list
	rm $(OBJ)*.o
