#include <stdio.h>
#include <string.h>

//char buf[] = "shashi";
int buf[] = {0, 1, 2, 3, 4, 5};
void binary(int n)
{
	static int i = 0;
	i++;
	if (n < 1)
		printf("i = %d\t%s\n", i, buf);
	else
	{
		buf[n-1] = 0;
		binary(n-1);
		buf[n-1] = 1;
		binary(n-1);
	}
}


int main()
{
//	printf("Strlen = %ld\n", strlen(buf));
//	binary(strlen(buf));
	binary(6);
	return 0;
}
