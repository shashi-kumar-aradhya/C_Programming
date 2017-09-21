#include <stdio.h>
#include <string.h>
char buf[10];
int f1()
{
	char name[] = "ABCDEF";
	static int i = 0;
	int n = sprintf(&buf[i++],"%c%c", name[0], name[1]);
	return n;
}
int main()
{
	int j = f1();
	strcpy(&buf[j], "CD");
	printf("%s\n", buf);
	return 0;
}
