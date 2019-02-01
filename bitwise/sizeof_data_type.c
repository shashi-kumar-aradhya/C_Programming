#include <stdio.h>
struct{
	int a;
	char b[50];
}temp;
/*typedef struct {
	temp a;
	int b;
}temp2;*/

#define SIZEOF(X) (long unsigned int)((X*)0+1)
#define MYSIZEOF(X) (long unsigned int)(((char *)&X+1) - ((char *)&X))
#define my_sizeof(x) ((char *)(&x + 1) - (char *)&x)

int main()
{
	printf("%ld", SIZEOF(int));
	printf("%ld", SIZEOF(struct temp *));
	printf("%ld", my_sizeof(int));
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
