/* Binary search */
/*
    Best case = Mid element 
    Worst case = Each iteration of while loop halves the search space 
       1. For simplicity n is the power of two n = 2 ^ k, (n = 128, k = 7)
       2. After K th iteration the search iteration consists of only one element 
          sine n = 2k, k = log2n
            (n = 2^k => k = log(n) / log 2)
    Average case = most likely worst case
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    int size = 0;
    int search_element = 0;
    int pos = -1;
    int i = 0;
    int high, low, mid;
    

    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);
    
    ptr = (int *)malloc(sizeof(int) * size);
    printf("\nEnter the  Array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("\nEnter the search element : ");
    scanf("%d", &search_element);
    
    /* Algorithm implementation */
    high = size - 1;
    low= 0;
    while (high >= low) {
        mid = (high + low) / 2;
        if (ptr[mid] > search_element)
        {
            high = mid - 1;
        }
        else if (ptr[mid] < search_element)
        {
            low = mid + 1;
        }
        else
        {
            pos = mid;
            break;
        }
    }
 
    if (pos != -1)
        printf("\nElement found at position : %d\n", pos);
    else
        printf("\nElement is not found\n");

    free(ptr);
    return 0;
}
