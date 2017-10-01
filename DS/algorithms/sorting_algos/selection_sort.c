/* Selectio sort*/
/*
   1. Divides the array into sorted and unsorted array
   2. Swaps first unsorted element with unsorted small element

    Analysis :
    1. Selecting the lowest elements requires scanning all n elements (this takes n-1 comparisions), finding the next small elements requires
      scanning remaining (n-1) elements and so on.. for (n-1) + (n-2) + (n-3) + ..... + 2 + 1 = (n * (n -1)) / 2 = n2
    2. Each of these scans requires swapping n-1 elements
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr, int i , int j)
{
    ptr[i] = ptr[i] ^ ptr[j];
    ptr[j] = ptr[i] ^ ptr[j];
    ptr[i] = ptr[i] ^ ptr[j];
}
void display(int *ptr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
int main()
{
    int *ptr = NULL;
    int size = 0;
    int i=0;
    int j = 0;
    int index;
    int small;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);

    ptr = (int *)malloc(sizeof(int) * size);
    printf("Enter the  Array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }
    printf("\n");

    /* Algorithm implementation */
    for (i = 0; i < size; i++) {
        small = ptr[i];
        index = 0;
        for(j = i+1; j < size; j++) {
            if(ptr[j] < small) 
            {
                small = ptr[j];
                index = j;
            }
        }
        if(index != 0) {
            swap(ptr, i, index);
            printf("Iteration = %d Array elements = ", i);
            display(ptr, size);
        }
        else 
            break;
    }

    printf("\nSorted array = ");
    display(ptr, size);
    free(ptr);
    return 0;
}
