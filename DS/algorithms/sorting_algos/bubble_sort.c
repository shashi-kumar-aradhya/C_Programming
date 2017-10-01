/* Bubble sort */

#include <stdio.h>
#include <stdlib.h>

/* Using typedef */
typedef enum { false, true } bool;

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
    bool flag = true;       //Flag is used for optimization when array is sorted already
 

    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);
    
    ptr = (int *)malloc(sizeof(int) * size);
    printf("\nEnter the  Array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    /* Algorithm implementation */
    for (i = 0; i < size && flag; i++) {
        flag = false;
        for(j = 0; j < size - i - 1; j++) {
            if(ptr[j+1] < ptr[j]) 
            {
                swap(ptr, j, j+1);
                flag = true;
            }
        }
        display(ptr, size);
    }

    display(ptr, size);
    free(ptr);
    return 0;
}
