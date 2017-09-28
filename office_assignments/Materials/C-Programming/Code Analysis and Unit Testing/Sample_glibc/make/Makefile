
CC = gcc
CFLAGS = -c -Wall -g
SRC = ../src
BIN = ../bin
INCLUDE = ../include
OBJ = ../obj
PKG = `pkg-config --cflags --libs glib-2.0`

$(BIN)/exe: $(OBJ)/main.o $(OBJ)/func.o
	$(CC) -o exe  $(PKG) $(OBJ)/main.o $(OBJ)/func.o 
	mv exe $(BIN)/
$(OBJ)/main.o: $(SRC)/main.c $(INCLUDE)/header.h
	$(CC)  $(PKG) $(CFLAGS) $(SRC)/main.c -I$(INCLUDE)
	mv main.o $(OBJ)/
$(OBJ)/func.o: $(SRC)/func.c $(INCLUDE)/header.h
	$(CC)  $(PKG) $(CFLAGS) $(SRC)/func.c -I$(INCLUDE)
	mv func.o $(OBJ)/
clean:
	rm $(OBJ)/*.o $(BIN)/exe 
	
