all :
	gcc -Wall -g ${FILE}.c -o ${FILE}.exe  -pthread

clean:
	rm -rf *.exe *.o *.i *.s *.S *.lst
valgrind :
#	valgrind --read-inline-info=yes --show-reachable=yes --leak-check=yes ./${FILE}.exe
	valgrind --read-inline-info=yes --leak-check=yes ./${FILE}.exe
