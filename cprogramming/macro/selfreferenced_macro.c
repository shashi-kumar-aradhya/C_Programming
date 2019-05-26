#define x (4 + y)
#define y (2 * x)



#define foo (4 + foo)


int main()
{
	printf("Value = %d\n", foo);
	x;
	y;
	return 0;
	
}
