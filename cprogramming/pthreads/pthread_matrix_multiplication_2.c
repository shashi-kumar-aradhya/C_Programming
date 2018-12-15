/**
 * In General:
 * To multiply an m×n matrix by an n×p matrix, the n's must be the same,
 * and the result is an m×p matrix.
 * matrix multiply rows cols
 Matrix 1 = m * n
 Matrix 2 = n * p
 (m*n) * ( n * p) = m * p

 for (c = 0; c < m; c++) 
 {
 for (d = 0; d < p; d++)
 {
 for (k = 0, sum = 0; k < n; k++) 
 {
 sum = sum + first[c][k]*second[k][d];
 }
 multiply[c][d] = sum;
 }
 }
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <pthread.h>

#define M 2
#define N 2
#define P 2
#define Q 2


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int *first;
int *second;
int *multiply;

typedef struct {
	int i;
	int j;
	int n;
}thread_data_t;

void *multiplication(void *arg)
{
	thread_data_t *ptr = (thread_data_t *)arg;
	int i = ptr->i;
	int j = ptr->j;
	int n = ptr->n;
	printf("n = %d i = %d j = %d\t", n, i, j);
	int k = 0;
	int sum = 0;
	for (k = 0, sum = 0; k < n; k++) 
	{
		sum = sum + first[i * k + k] * second[k * j + j];
	}
	multiply[i * j + i] = sum;
	printf("Sum = %d\n", sum);

#if 0
	pthread_mutex_lock(&mutex);
	multiply[ j * i + j] = sum;
	pthread_mutex_unlock(&mutex);
#endif
	return NULL;
}

int main(int argc, char *argv[])
{
	int i, j;
	int m, n, p, q;

	thread_data_t data;

	printf("Enter m : ");
	scanf("%d", &m);
	printf("Enter n : ");
	scanf("%d", &n);
	printf("Enter p : ");
	scanf("%d", &p);
	printf("Enter q : ");
	scanf("%d", &q);

	if (n != p) {
		printf("Matrix multiplication is not possible\n");
		return 0;
	}

	first = (int *) malloc(sizeof(int) * m * n);
	second= (int *) malloc(sizeof(int) * p * q);
	multiply = (int *) malloc(sizeof(int) * m * q);

	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			first[i * j + j] = 1 + i + j;
		}
	}

	for (i = 0; i < p; i++)
	{
		for(j = 0; j < q; j++)
		{
			second[i * j + j] = 2 + i + j;
		}
	}

	printf("\n first matrix \n");
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", first[i * j + j]);
		}
		printf("\n");
	}

	printf("\n second matrix \n");
	for (i = 0; i < p; i++)
	{
		for(j = 0; j < q; j++)
		{
			printf("%d\t", second[i * j + j]);
		}
		printf("\n");
	}
	data.n = n;
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < q; j++)
		{
			data.i = i;
			data.j = j;
			multiplication(&data);
		}
	}
#if 0
	return 0;

	data.n = n;
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < q; j++)
		{
			data.i = i;
			data.j = j;
			printf("n = %d i = %d j = %d\n", data.n, data.i, data.n);
			multiplication((void *)&data);
			sleep(1);
		}
	}

#endif
	printf("\n matrix multiplication \n");
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < q; j++)
		{
			printf("%d\t", multiply[i * j + j]);
		}
		printf("\n");
	}

	printf("end\n");
	return 0;
}
