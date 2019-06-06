#include <stdio.h>

static inline __attribute__((always_inline)) int plus_one(int x) {
    return x + 1;
}

int main()
{
	int i = 10;
	i = plus_one(i);
	printf("Value = %d\n", (i));
	return 0;
}
