#include <stdio.h>

void sort(int list[], int size);
int main()
{
	int array[] = {43,68,7,5,25};
	sort(array, sizeof(array) / sizeof(int));
	return 0;
}


void sort(int list[], int size)
{
	printf("Size = %d\n", size);
	int count = 0;
	int temp, i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (list[i] > list[j])
			{
				count++;
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	printf("Count = %d\n", count);
}
