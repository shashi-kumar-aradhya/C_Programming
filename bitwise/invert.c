#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged
 **/
#define INVERT(x,p,n) (x ^ (~(~0 << n) << (p+1-n)))


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

int main(int argc, char *argv[])
{
	int x = atoi(argv[1]);
	int p = atoi(argv[2]);
	int n = atoi(argv[3]);
	int temp1 = ~0 << n;
	int temp2 = temp1 << (p+1-n);
	int temp3 = ~ temp2;
	printf("x = ");
	printbits(x);
	printf("temp1= ");
	printbits(temp1);
	printf("temp2= ");
	printbits(temp2);
	printf("temp3= ");
	printbits(temp3);
	int temp4 = x ^ temp3;
	printf("temp4= ");
	printbits(temp4);
	return 0;
}
