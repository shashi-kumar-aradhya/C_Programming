#include<stdio.h>

extern void printbits(unsigned int);

int main()
{
	int number = 0,n, i =0;
	while(1){
		i =0;
		printf("Enter the number : ");
		scanf("%d", &number);
		n = number;
		while(n){
		printbits(n);
		printf("\n");
		printbits(n-1);
		printf("\n");
		printbits(n &= (n-1));
		printf("i = %d\n", i);
		i++;
		}
		printf("\n");
		
		n = n ^ (~0);
		printbits(n);
		printf("\n");
	}
	return 0;
}

