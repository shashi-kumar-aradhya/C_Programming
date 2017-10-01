/* Selectio sort*/
/*
    1. Divides the array into sorted and unsorted array
    2. Swaps first unsorted element with unsorted small element
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
    printf("\nEnter the  Array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

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
        if(index != 0)
        swap(ptr, i, index);
        display(ptr, size);
    }

    display(ptr, size);
    free(ptr);
    return 0;
}
