#include <stdio.h>

#define INDEX_NUM	5 

typedef enum {
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	MAX,
}MAXINPUT_t;

unsigned int mtpc[MAX+1][INDEX_NUM];

void LookUpInvalid(unsigned int input[][INDEX_NUM])
{
	int i;
	for (i = 0; i < INDEX_NUM; i++)
	{
		(*input)[i] = 0xff;
		printf("LookUp : %p, i = %d\n", &((*input)[i]), i);
	}

}
void binary_search(unsigned int *array)
{
	printf("Binary search address = %p\n", array);
	printf("\n");
} 

int main()
{
	int i = 0;
	printf("Total size = %ld, MTPC_MAX = %d\n", sizeof(mtpc), MAX);
	for(i = 0; i <=MAX; i++)
	{
		printf("client = %d\t address = %p\n", i, &mtpc[i]);
		LookUpInvalid(&mtpc[i]);
		printf("\n");
		binary_search(mtpc[i]);
		printf("\n");
	}
	return 0;
}
