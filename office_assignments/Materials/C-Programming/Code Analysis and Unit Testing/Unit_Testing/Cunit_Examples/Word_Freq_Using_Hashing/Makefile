CC = gcc
#used standard c99 where the __func__ is available to print function names
CFLAGS = -Wall -c -g -DTRACE_FEATURE -std=c99 -DTEST_CASE
OFLAGS = -o
BIN = bin/
OBJ = obj/
CUNIT_DIR = /root/ashwani/CUnit-2.1-2
AUT_INC = -I ${CUNIT_DIR}

$(BIN)htest: $(OBJ)WFREQ_Testmain.o $(OBJ)WFREQ_build_array_of_words_from_file.o $(OBJ)WFREQ_hash.o $(OBJ)WFREQ_Test.o $(OBJ)WFREQ_utility.o
	$(CC) $(OFLAGS)htest $(OBJ)WFREQ_Testmain.o $(OBJ)WFREQ_build_array_of_words_from_file.o $(OBJ)WFREQ_hash.o $(OBJ)WFREQ_Test.o $(OBJ)WFREQ_utility.o ${CUNIT_DIR}/CUnit/Sources/.libs/libcunit.a
	mv htest $(BIN)

$(OBJ)WFREQ_Testmain.o: WFREQ_Testmain.c WFREQ_Test.h WFREQ_header.h 
	$(CC) $(CFLAGS) WFREQ_Testmain.c WFREQ_header.h  ${AUT_INC}
	mv WFREQ_Testmain.o $(OBJ)

$(OBJ)WFREQ_build_array_of_words_from_file.o: WFREQ_build_array_of_words_from_file.c WFREQ_header.h
	$(CC) $(CFLAGS) WFREQ_build_array_of_words_from_file.c WFREQ_header.h
	mv WFREQ_build_array_of_words_from_file.o  $(OBJ)

$(OBJ)WFREQ_hash.o: WFREQ_hash.c WFREQ_header.h
	$(CC) $(CFLAGS) WFREQ_hash.c WFREQ_header.h
	mv WFREQ_hash.o  $(OBJ)

$(OBJ)WFREQ_Test.o: WFREQ_Test.c WFREQ_Test.h WFREQ_header.h
	$(CC) $(CFLAGS) WFREQ_Test.c WFREQ_header.h ${AUT_INC}
	mv WFREQ_Test.o $(OBJ)

$(OBJ)WFREQ_utility.o: WFREQ_utility.c WFREQ_header.h 
	$(CC) $(CFLAGS) WFREQ_utility.c WFREQ_header.h
	mv WFREQ_utility.o $(OBJ)
clean: 
	rm $(BIN)htest
	rm $(OBJ)*.o
