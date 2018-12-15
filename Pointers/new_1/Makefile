all:
#	gcc -S -o ${FILE}.c 

#	as ${FILE}.c -o ${FILE}.s
	gcc -Wall -g -S ${FILE}.c -o ${FILE}.exe
	chmod +x ${FILE}.exe
#	objdump -DS $(FILE).exe > startup.lst

clean:
	rm -rf *.i *.o *.exe *.s *.S
