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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#define M 10
#define N 10
#define P 10
#define Q 10

int first[M][N];
int second[P][Q];
int multiply[M][Q];

typedef struct {
	pthread_t thread_id;
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
	int k = 0;
	int sum = 0;
	for (k = 0, sum = 0; k < n; k++) 
	{
		sum = sum + first[i][k] * second[k][j];
	}

	pthread_mutex_lock(&mutex);
	multiply[i][j] = sum;
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
//	return NULL;
}

int main(int argc, char *argv[])
{
	int i, j;
	int m, n, p, q;

	thread_data_t data[M*Q];

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
	printf("resultant matrix is order = %d * %d\n size allocated = %ld\n", m, q, sizeof(thread_data_t) * m * q);
	
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			first[i][j] = 1 + i + j;
		}
	}

	for (i = 0; i < p; i++)
	{
		for(j = 0; j < q; j++)
		{
			second[i] [j] = 2 + i + j;
		}
	}

	printf("\n first matrix \n");
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", first[i][j]);
		}
		printf("\n");
	}

	printf("\n second matrix \n");
	for (i = 0; i < p; i++)
	{
		for(j = 0; j < q; j++)
		{
			printf("%d\t", second[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < q; j++)
		{
			data[i+j].n = n;
			data[i+j].i = i;
			data[i+j].j = j;
			pthread_create(&data[i+j].thread_id, NULL, multiplication, (void *)&data[i+j]);
//			multiplication(&data[i+j]);
		}
	}
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < q; j++)
		{
			pthread_join(data[i+j].thread_id, NULL);
		}
	}
	
	printf("\n matrix multiplication \n");
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < q; j++)
		{
			printf("%d\t", multiply[i][j]);
		}
		printf("\n");
	}

	printf("end\n");
	return 0;
}
