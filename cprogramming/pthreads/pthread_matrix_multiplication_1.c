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

int first[M][N];
int second[P][Q];
int multiply[M][Q];

typedef struct {
	int i;
	int j;
	int n;
}thread_data_t;

#if 0
void *multiplication(void *arg)
{
	thread_data_t *ptr = (thread_data_t *)arg;
	int i = ptr->i;
	int j = ptr->j;
	int n = ptr->n;
	printf("n = %d i = %d j = %d\n", n, i, j);
	int k = 0;
	int sum = 0;

	for (k = 0; k < n; k++) {
		sum = sum + first[ k * i + i]*second[k * j + j];
	}
	pthread_mutex_lock(&mutex);
	multiply[ j * i + j] = sum;
	pthread_mutex_unlock(&mutex);
	return NULL;
}
#endif

int main(int argc, char *argv[])
{
	int i, j, k;
	int m, n, p, q;
	int sum;

	thread_data_t data;
/*
	printf("Enter m : ");
	scanf("%d", &m);
	printf("Enter n : ");
	scanf("%d", &n);
	printf("Enter p : ");
	scanf("%d", &p);
	printf("Enter q : ");
	scanf("%d", &q);
*/
	if (N != P) {
		printf("Matrix multiplication is not possible\n");
		return 0;
	}
/*
	first = (int *) malloc(sizeof(int) * m * n);
	second= (int *) malloc(sizeof(int) * p * q);
	multiply = (int *) malloc(sizeof(int) * m * q);
*/
	for (i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			first[i][j] = 1 + i + j;
		}
	}

	for (i = 0; i < P; i++)
	{
		for(j = 0; j < Q; j++)
		{
			second[i] [j] = 2 + i + j;
		}
	}

	printf("\n first matrix \n");
	for (i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d\t", first[i][j]);
		}
		printf("\n");
	}

	printf("\n second matrix \n");
	for (i = 0; i < P; i++)
	{
		for(j = 0; j < Q; j++)
		{
			printf("%d\t", second[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < M; i++) 
	{
		for (j = 0; j < Q; j++)
		{
			for (k = 0, sum = 0; k < N; k++) 
			{
				//sum = sum + first[ k * i + i]*second[k * j + j];
 				//sum = sum + first[c][k]*second[k][d];
 				sum = sum + first[i][k] * second[k][j];
			}
 			//multiply[c][d] = sum;
			multiply[i][j] = sum;
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
	for (i = 0; i < M; i++)
	{
		for(j = 0; j < Q; j++)
		{
			printf("%d\t", multiply[i][j]);
		}
		printf("\n");
	}

	printf("end\n");
	return 0;
}
