#include <stdio.h>
#include <stdlib.h>


void towers(int n,char frompeg,char topeg,char auxpeg)
{
	if (n == 1)
	{
		printf("\n%s %c %s %c","Move disk 1 frompeg", frompeg, "to peg", topeg);
		return;
	}
	//Move top n-1 disks from A to B, using C as auxiliary
	towers(n-1, frompeg, auxpeg, topeg);

	printf("\n%s %d %s %c %s %c","Move disk",n, "frompeg", frompeg, "to peg", topeg);
	//Move n-1 disks from B to C, using C as auxiliary
	towers(n-1, auxpeg, topeg, frompeg);
}

int main(int argc, char *argv[])
{
	towers(atoi(argv[1]), 'A', 'C', 'B');
	printf("\n");
	return 0;
}
