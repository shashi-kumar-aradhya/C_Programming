static :
	gcc -c add.c
	gcc -c sub.c
	ar rs libheymath.a add.o sub.o
	gcc -I . -c addDemo.c
	gcc -o addDemo addDemo.o libheymath.a
	gcc -o addDemo -L . addDemo.o -lheymath

dynamic :
	gcc -Wall -fPIC -c add.c
	gcc -Wall -fPIC -c sub.c
	gcc -shared -o libheymath.so add.o sub.o
	gcc -c addDemo.c
	gcc -o addDemo addDemo.o -lheymath

clean :
	rm -rf addDemo *.a *.o *.so
