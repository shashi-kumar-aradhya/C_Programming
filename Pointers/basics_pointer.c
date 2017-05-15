#include <stdio.h>
	
	    d		     c 	             b		     a
	|---------|	|---------|	 |--------|	 |--------|
	|   40	 -|---->|   30	 -|----->|   20	 -|----->|   10	  |
	|---------|	|---------|	 |--------|	 |--------|
	    50		    40		     30		     20	

int main()
{
	int a = 10;
	int *b = &a;
	int **c = &b;
	printf("a = %d\n", a);		//a = 10
	printf("&a = %p\n", &a);	//&a = 20
	printf("b = %p\n",b);		//b = 20
	printf("*b = %p\n",*b);		//*b = 10
	printf("&b = %p\n",&b);		//&b = 30
	printf("c = %p\n",c);		//c = 30
	printf("*c = %p\n",*c);		//*c = 20
	printf("**c = %p\n",**c);	//**c = 10
	printf("&c = %p\n",&c);		//&c = 40
	return 0;
}
