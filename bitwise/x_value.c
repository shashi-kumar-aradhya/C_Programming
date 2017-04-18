#include <stdio.h>

#define BIT(x) (1 << x)

/**
 *  Aim : Setting p-th position 
 */
#define SET(x, p) ( x | (1 << p))

/**
 *  Aim : Clears the p-th position
 */
#define CLR(x, p) ( x & ~(1 << p))

/**
 *  Aim : sets p-th position value to x 
 */
#define SET_X(value, pos, x) (value = ((value & ~(1 << pos)) | ( x << pos)))

/**
 *  Aim : Rotates given number to left by n-bits 
 */
#define ROTATE_LEFT(value, n) (((unsigned int)value >> ((sizeof(int) * 8) - n)) | (value << n))

/**
 *  Aim : Rotate given number to right by n-bits 
 */
#define ROTATE_RIGHT(value, n) (((unsigned int)value >> (n)) | ((value & ~(~0<< n)) << (sizeof(int)*8 - n)))

/**
 *  Aim : Righjt adjusted n-bit field of x that begins at position p 
 *  GETBITS(x, 4, 3) returns the three bits in position 4, 3, 2, right adjusted
 */
#define GETBITS(x, p, n) (((unsigned int)x >> (p-n+1)) & ~(~0 << n))

/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position p set to the rightmost n bits of y, leaving the other bits unchanged
 */
#define SETBITS(x, p, n, y) ((x & ~((~0 << n) << (p-n+1))) | (( y & ~(~0 << n))<< (p-n+1)))

/**
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged
 **/
#define INVERT(x,p,n) (x ^ (~(~0 << n) << (p-n+1)))

#define SQUARE(x) (x & (x-1))

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
int bitcount (unsigned int x)
{
	int count = 0;
	while (x) {
		if( x & 1)
			count++;
		x >>= 1;
	}
	printf("Bitcount = %d\n", count);
	return count;

}

int main()
{
	int i = 0;
	int count = 0;
	int a = 0xa;
	for (a = 0; a < 100; a++) {
		i = a;
		count = 0;
		printf("\n******************************************************************START*******************************************************************************\n");
		while (i) {
			printf("X = %x\t", i);
			printbits(i);
			printf("  ");
			printf(" X-1 = %x\t", i-1);
			printbits(i-1);
			printf("  ");
			i = SQUARE(i);
			printf("After X = %x\t", i);
			printbits(i);
			printf("  ");
			count++;
			printf("Count = %d\n", count);

		}
		printf("COUNT = %d\n", count);
		bitcount(a);
		printf("\n******************************************************************END*********************************************************************************\n");
	}
	/*
	   for (i = 0; i < 100; i++) {
	   printf("X = %x\t", i);
	   printbits(i);
	   printf("  ");
	   printf(" X-1 = %x\t", i-1);
	   printbits(i-1);
	   printf("  ");
	   printf("Square = %x\t", SQUARE(i));
	   printbits(SQUARE(i));
	   printf("\n");
	   }
	 */
	/*
	   printf("GETBIT value = %x\n", GETBITS(value,3, 3));
	   printbits(GETBITS(value,3, 3));
	   printf("\n");
	   printf("SETBIT value = %x\n", SETBITS(value,3, 3, 0xf));
	   printbits(SETBITS(value,3, 3, 0xf));
	   printf("\n");
	 */
	/*
	   for (i = 0; i < 32; i++) {
	   printf("i = %d ", i);
	   printf("SET = ");
	   printbits(SET(value, 2));
	   printf("CLR = ");
	   printbits(CLR(value, 1));
	   printf("RIGHT = ");
	   printbits(ROTATE_RIGHT(value, i));
	   printf("LEFT = ");
	   printbits(ROTATE_LEFT(value, i));
	   printf("\n");
	   }
	 */
	/*
	   printf("Value right shift = ");
	   printbits((unsigned int)value >> (1));
	   printf("Value left shift = ");
	   printbits(((value & ~(~0<< 1)) << (sizeof(int)*8 - 1)));
	 */
	//printf("value = %d\n", set(0xa0, 4, 0));
	return 0;
}
