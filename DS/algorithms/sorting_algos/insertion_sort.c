/* Selectio sort*/
/*
    1. Divides the array into sorted and unsorted array, the sorted array will be expanded one element at a time
    2. Find the correct place of the sorted array to place the 1st element of the unsorted part
       by searching through all of the sorted elements

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
//    int *ptr = NULL;
    int ptr[100];
    int size = 0;
    int i=0;
    int j = 0;
    int small;
 

    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);
    
  //  ptr = (int *)malloc(sizeof(int) * size);
    printf("\nEnter the  Array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    /* Algorithm implementation */
    for (i = 1; i < size; i++) {
        small = ptr[i];
        j = i - 1;
        while(j >= 0 && ptr[j] > small) 
        {
            ptr[j+1] = ptr[j];
            j--;
        }
        ptr[j+1] = small;
        display(ptr, size);
    }

    display(ptr, size);
  //  free(ptr);
    return 0;
}
