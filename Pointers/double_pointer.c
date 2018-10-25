#include <stdio.h>

#define OVERRIDE_INDEX_NUM	5 

typedef enum {
	MTPM,
	BDSAR,
	RTSAR,
	SHM,
	UTA,
	MTPC_MAX,
}MTPC_t;

unsigned int mtpc[MTPC_MAX+1][OVERRIDE_INDEX_NUM];

void LookUpInvalid(unsigned int input[][OVERRIDE_INDEX_NUM])
{
	int i;
	for (i = 0; i < OVERRIDE_INDEX_NUM; i++)
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
	printf("Total size = %ld, MTPC_MAX = %d\n", sizeof(mtpc), MTPC_MAX);
	for(i = 0; i <=MTPC_MAX; i++)
	{
		printf("client = %d\t address = %p\n", i, &mtpc[i]);
		LookUpInvalid(&mtpc[i]);
		printf("\n");
		binary_search(mtpc[i]);
		printf("\n");
	}
	return 0;
}
