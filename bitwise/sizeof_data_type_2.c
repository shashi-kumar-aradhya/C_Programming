#include <stdio.h>
struct{
	int a;
	char b[50];
}temp;
/*typedef struct {
	temp a;
	int b;
}temp2;*/

#define my_sizeof(x) ((char *)(&x + 1) - (char *)&x)

int main()
{
//	printf("%ld", my_sizeof(int));
	printf("%ld", my_sizeof(struct temp *));
/*
	temp2 temp3;
	printf("%d\n",SIZEOF(temp3));
	printf("%d\n",SIZEOF(temp3.a));
	printf("%d\n",SIZEOF(temp3.b));
	printf("%d\n",SIZEOF(temp3.a.a));
	printf("%d\n",SIZEOF(temp3.a.b));
printf("%d\n", sizeof(int *));
*/
	return 0;


}
