#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 30
#define MAX 5
#define LOOP 2
//typedef int array[MAX];
//static  int global_data[LOOP][MAX];
typedef short int array[MAX];
static short int global_data[LOOP][MAX];


array new[LOOP];
/*
   array * becomes (short int (*) [MAX]), when it is used as a pointer please use (*new) to access the member

 */
void fun(array *new)
//void fun()
{
	int i = 0;
	int j = 0;
	printf("\nIn fun\n");
	for (j = 0; j < LOOP; j++)
	{
		for(i = 0; i < MAX; i++)
		{
			printf("address &new[%d][%d]= %p\n", j, i, &new[j][i]);
			printf("address new[%d][%d]= %d\n", j, i, new[j][i]);
			//printf("address new[%d][%d]= %d\n", j, i, new[j][i]);
		}
	}
	memcpy(global_data, new, sizeof(global_data));
	for (j = 0; j < LOOP; j++)
	{
		for(i = 0; i < MAX; i++)
		{
			printf("after memcpy [%d][%d] = %d\n", j, i, global_data[j][i]);
		}
	}

}
int main()
{
	array new[LOOP];
	int i;
	int j = 0;
	printf("size = %ld, address = %p address_1 = %p\n", sizeof(new)/sizeof(new[0]), new, &new);
	for (j = 0; j < LOOP; j++)
	{
		printf("address[%d] = %p\n",j, &new[j]);
		for(i = 0; i < MAX; i++)
		{
			new[j][i] =(j*10) + i + 2;
			printf("address[%d][%d] = %p--> value = %d\n",j, i, &new[j][i], new[j][i]);
		}
	}
//	fun(new);
	fun(&new);
//	fun();
	/* 	
		fun(new);
		array_to_pointers.c:5:6: note: expected ‘short int (*)[30]’ but argument is of type ‘short int *’
		void fun(array *new)	
	 */	
	return 0;
}
