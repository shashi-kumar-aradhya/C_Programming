/* Linear search */
/*
    Best case = search element is first element = 1
    Worst case = last element = n (or element is not present)
    Average case = (best case + worst case) / 2 = (1 + n) / 2
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
    for(i = 0; i < size; i++) {
        if(ptr[i] == search_element) {
            pos = i;
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
