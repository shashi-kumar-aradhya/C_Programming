all:
#	gcc -S -o ${FILE}.c 
#	as ${FILE}.c -o ${FILE}.s
	gcc -Wall -g -save-temps ${FILE}.c
	as -alhnd ${FILE}.s > ${FILE}.lst
	mv a.out ${FILE}.exe
	chmod +x ${FILE}.exe
#	gcc -Wall -g  ${FILE}.o -o ${FILE}.exe
      	#objdump -S --disassemble ${FILE}.o > ${FILE}.dump
#	objdump -DS $(FILE).exe > startup.lst

clean:
	rm -rf *.i *.o *.exe *.s *.S
