CC = gcc
#used standard c99 where the __func__ is available to print function names
CFLAGS = -Wall -c -g -DTRACE_FEATURE -std=c99 -DTEST_CASE
OFLAGS = -o
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
BIN = bin/
INCLUDE = -I../include/
HEADER = ../include/
SRC = ../src/
OBJ = obj/
CUNIT_DIR = /root/ashwani/CUnit-2.1-2
AUT_INC = -I ${CUNIT_DIR}
#CFLAGS += ${CUNIT_DIR}

$(BIN)ll_testout: $(OBJ)llTestmain.o $(OBJ)mylistfunctions.o $(OBJ)list_error.o $(OBJ)linked_list_Test.o 
	$(CC) $(OFLAGS)ll_testout $(OBJ)llTestmain.o $(OBJ)linked_list_Test.o $(OBJ)mylistfunctions.o $(OBJ)list_error.o ${CUNIT_DIR}/CUnit/Sources/.libs/libcunit.a
	mv ll_testout $(BIN)

$(OBJ)llTestmain.o: llTestmain.c $(HEADER)mylist.h linked_list_Test.h 
	$(CC) $(CFLAGS) llTestmain.c $(INCLUDE) ${AUT_INC}
	mv llTestmain.o $(OBJ)

$(OBJ)mylistfunctions.o: $(SRC)mylistfunctions.c $(HEADER)mylist.h 
	$(CC) $(CFLAGS) $(SRC)mylistfunctions.c $(INCLUDE)
	mv mylistfunctions.o  $(OBJ)

$(OBJ)list_error.o: $(SRC)list_error.c $(HEADER)mylist.h 
	$(CC) $(CFLAGS) $(SRC)list_error.c $(INCLUDE)
	mv list_error.o  $(OBJ)

$(OBJ)linked_list_Test.o: linked_list_Test.c linked_list_Test.h
	$(CC) $(CFLAGS) linked_list_Test.c $(INCLUDE) ${AUT_INC}
	mv linked_list_Test.o $(OBJ)

clean: 
	rm $(BIN)ll_testout
	rm $(OBJ)*.o
