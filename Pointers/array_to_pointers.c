#include <stdio.h>

#define MAX 30
typedef short int array[MAX];
static short int global_data[MAX];
/*
	array * becomes (short int (*) [MAX]), when it is used as a pointer please use (*new) to access the member

*/
void fun(array *new)
{
	int pow;
	int pow_1;
	int i = 0;
	printf("\nIn fun\n");
	for(i = 0; i < MAX; i++)
	{
		pow = new[0][i];
		pow_1 = (*new)[i];
		printf("i = %d, value = %d,  value_1 = %d value_2 = %d\n", i, pow, pow_1, *new[i]);
		printf("address &new[%d]= %d\n", i, &new[i]);
		printf("address &new[0][%d]= %d\n", i, &new[0][i]);
		printf("address (*new)[%d]= %d\n", i ,&(*new)[i]);
	}
	memcpy(global_data, new, sizeof(global_data));
	for(i = 0; i < MAX; i++)
	{
		printf("after memcpy [%d] = %d\n", i, global_data[i]);
	}

}
int main()
{
	array new = {1,2,3};
	int i;
	printf("size = %ld, address = %p address_1 = %p\n", sizeof(new)/sizeof(new[0]), new, &new);
	for(i = 0; i < MAX; i++)
	{
		new[i] = i + 2;
		printf("address %d = %d\n", i, &new[i]);
	}
	
	fun(&new);
	/* 	
	   fun(new);
	   array_to_pointers.c:5:6: note: expected ‘short int (*)[30]’ but argument is of type ‘short int *’
	   void fun(array *new)	
	*/	
	return 0;
}
