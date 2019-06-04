#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int binary_search(int array[], int low, int high, int search)
{
	int mid;
	if (low > high)
		return -1;
//	mid = (low +(high - low))/2;
	mid = (low+high)/2;
	if(array[mid] == search)
		return mid;
	else if(array[mid] > search)
		return (binary_search(array, low, mid-1, search));
	else
		return (binary_search(array, mid+1, high, search));
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

int main(int argc, char *argv[])
{
	
	int array[MAX] = {0,1,2,3,4,5,6,7,8,9};
	printf("returned pos = %d\n", binary_search(array, 0, MAX-1, atoi(argv[1])));
	printf("returned pos = %d\n", binarySearch(array, 0, MAX-1, atoi(argv[1])));
	return 0;
}
