GCC= gcc -g -Wall -Winline
GCC_1= gcc -g -Wall 

all:
	${GCC} inline_00.c -o inline_00.exe
	gcc -S -o inline_00.s inline_00.c
	${GCC} inline_01.c -o inline_01.exe
	gcc -S -o inline_01.s inline_01.c

all_1:
	${GCC_1} inline_00.c -o inline_00_0.exe

clean :
	rm -rf *.exe
