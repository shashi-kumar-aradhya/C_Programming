void testarr()
{
	int **aptr = NULL;
	int m = 3, n = 2;
	int d = 0;
	aptr = (int**)malloc(m * sizeof(int*));

	int i = 0, j = 0;
	for (i = 0; i < m; i++)
	{
		aptr[i] = (int*) malloc(sizeof(int) * n);
	} 

	for (i = 0; i < m; i++)
	{
		int *ptr = aptr[i];
		for (j = 0; j < n; j++)
		{
			*(ptr + j) =  ++d;
		}
	}

	//display
	for (i = 0; i < m; i++)
	{
		printf("\n ");

		int *ptr = aptr[i];
		for (j = 0; j <= n; j++)
		{
			printf(" %d ", *(ptr + j));
		}
	}
}
