#include <stdio.h>
#define SET(x, p) ( x | (1 << p))
#define CLR(x, p) ( x & ~(1 << p))
#define SET_X(value, pos, x) (value = ((value & ~(1 << pos)) | ( x << pos)))
#define ROTATE_LEFT(value, n) (((unsigned int)value >> ((sizeof(int) * 8) - n)) | (value << n))
#define ROTATE_RIGHT(value, n) (((unsigned int)value >> (n)) | ((value & ~(~0<< n)) << (sizeof(int)*8 - n)))
void printbits(unsigned int value)
{
	int i = sizeof(int) * 8 - 1;
	for (; i >= 0; i--) {
		if ( value & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("  ");
	return;
}	


int main()
{
	int i = 0;
	unsigned value = 0x1234;
	printf("Bianry value = %x\t", value);
	printbits(value);
	printf("\n");
	for (i = 0; i < 32; i++) {
		printf("i = %d ", i);
		/*
		   printf("SET = ");
		   printbits(SET(value, 2));
		   printf("CLR = ");
		   printbits(CLR(value, 1));
		 */
		printf("RIGHT = ");
		printbits(ROTATE_RIGHT(value, i));
		printf("LEFT = ");
		printbits(ROTATE_LEFT(value, i));
		printf("\n");
	}
	/*
	   printf("Value right shift = ");
	   printbits((unsigned int)value >> (1));
	   printf("Value left shift = ");
	   printbits(((value & ~(~0<< 1)) << (sizeof(int)*8 - 1)));
	 */
	//printf("value = %d\n", set(0xa0, 4, 0));
	return 0;
}
