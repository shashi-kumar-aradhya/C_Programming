static inline __attribute__((always_inline)) void pow_check(int v)
{
	if (v && !(v & (v - 1)))
		printf("Power of two\n");
	else
		
		printf("Not power of two\n");
}

int main(int argc, char *argv[])
{
	int value = atoi(argv[1]);
	pow_check(value);
	return 0;
}
