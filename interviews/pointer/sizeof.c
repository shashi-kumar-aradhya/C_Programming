#include <stdio.h>
#include <stdlib.h>
struct Empty {

};
struct Empty_1 {
int one;
};

int main()
{
	void *data = (void *)malloc(sizeof(int));
	int *data_i = (void *)malloc(sizeof(int));
	float *data_f = (void *)malloc(sizeof(int));
	double *data_d = (void *)malloc(sizeof(int));
	int diff = -1;
	int diff_1 = -1;

	struct Empty ten[10];
	struct Empty_1 ten_1[10];
	printf("int = %ld\n", sizeof(*data));
	printf("int_i = %ld\n", sizeof(*data_i));
	printf("int_f = %ld\n", sizeof(*data_f));
	printf("int_d = %ld\n", sizeof(*data_d));

	data = (void *)malloc(sizeof(float));
	printf("float = %ld\n", sizeof(*data));

	data = (void *)malloc(sizeof(double));
	printf("double = %ld\n", sizeof(*data));

	printf("empty = %d\n",(int)sizeof(struct Empty));
	printf("ten = %d\n",(int)sizeof(ten));
//	diff = (&ten[1] - &ten[0]);
	diff_1 = (&ten_1[1] - &ten_1[0]);
//	printf("address = %ld\n", diff);
	printf("address = %ld\n", diff_1);
	return 0;

}
