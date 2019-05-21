#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_1(unsigned int n)
//char * print_1(unsigned int n)
{
//	static char arr[33];
	int i;
//	memset(arr, '\0', sizeof(arr));
	for(i = (sizeof(int)*8-1); i >= 0; i--)
	{
		if (n & (1 << i))
//			arr[i+2] = '1';
			printf("1");
		else
			//arr[i+2] = '0';
			printf("0");
	}
	printf("\n");
//	printf("%35s\t",arr);
//	return arr;
}


int count_one (int n)
{
	int count = 0;
	while( n )
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int main()
{
	int i = 0;
	printf("%10s\t%10s\t%35s\n","Input", "BitCount","Binary format");
	while( i < (sizeof(int) * 8 -1))
	{
		printf("%10d\t",i);
//		printf("%35s\t", print(i));
		printf("%10d\t",count_one(i));
		print_1(i);
		i++;
	}
	return 0;

}
