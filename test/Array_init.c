#include <stdint.h>
typedef struct {
	uint32_t *track;
	uint32_t start;
}temp_t;
#define DECLARE_MEMORY_POOL(index,size,count)\
uint32_t gMemPool_##index[count][size];\
uint32_t gMemPoolTrack_##index[count/sizeof(uint32_t)] = {0};
#include "mem.def"

temp_t Alloc[] = {
#define DECLARE_MEMORY_POOL(index,size,count)\
{gMemPoolTrack_##index, (uint32_t) gMemPool_##index},
#include "mem.def"
};
		
int main() 
{

	printf("Size = %lu\n", sizeof(Alloc) / sizeof(temp_t));
	return 0;
}
