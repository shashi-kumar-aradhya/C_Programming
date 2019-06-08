

#define MIN(x,y,r) do {r = y ^ ((x ^ y) & -(x < y));}while(0)
#define MAX(x,y,r) do {r = x ^ ((x ^ y) & -(x < y));}while(0)

int main( int argc, char *argv[])
{
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int r = 0;
	MIN(x,y,r);
	printf("Min = %d\n", r);
	MAX(x,y,r);
	printf("Max = %d\n", r);
	return 0;
}
