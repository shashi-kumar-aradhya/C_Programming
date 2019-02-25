#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 

#include "os.h"

#ifndef LENGTH
#define LENGTH 10
#endif

typedef struct{
//	pthread_t thread_id;
	int *ptr;
        int l;
	int h;
}thread_data;
int *shm_array; 
int global;  
OsCriticalSection cs;


void insertionSort(int arr[], int n); 
void merge(int a[], int l1, int h1, int h2); 
 
void *mergeSort(void *data)
{ 
    thread_data *ptr = (thread_data *)data;
    int *a = ptr->ptr;
    int l = ptr->l;
    int h  = ptr->h;
    int len=(h-l+1); 
  
    // Using insertion sort for small sized array 
    if (len<=5) 
    { 
        insertionSort(a+l, len); 
        return; 
    } 
  
    pthread_t lpid,rpid; 
    //lpid = fork(); 
    OsCriticalSectionEnter(&cs);
    printf("Thread id = %ld\t global_count = %d\n", pthread_self(), global);
    ptr->ptr = a;
    global++;
    ptr->l = l;
    ptr->h =l+len/2-1;
    pthread_create(&lpid, NULL, mergeSort, (void *)ptr);
    if (lpid<0) 
    { 
        // Lchild proc not created 
        perror("Left Child Proc. not created\n"); 
        _exit(-1); 
    } 
    printf("Left Child Proc. created = %d\n", lpid); 
    OsCriticalSectionLeave(&cs);
    
    OsCriticalSectionEnter(&cs);
    printf("Thread id = %ld\t global_count = %d\n", pthread_self(), global);
    ptr->ptr = a;
    global++;
    ptr->l = l+len/2;
    ptr->h =h;
    pthread_create(&lpid, NULL, mergeSort, (void *)ptr);
    if (lpid<0) 
    {   
        // Lchild proc not created 
        perror("Right Child Proc. not created\n"); 
        _exit(-1); 
    }   
    printf("Right Child Proc. created = %d\n", rpid); 
    OsCriticalSectionLeave(&cs);

  
    // Wait for child processes to finish 
//    waitpid(lpid, &status, 0); 
//    waitpid(rpid, &status, 0); 
      pthread_join(lpid, NULL);
      pthread_join(rpid, NULL);
  
    // Merge the sorted subarrays 
    merge(a, l, l+len/2-1, h); 
} 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
    OsCriticalSectionEnter(&cs);
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
    OsCriticalSectionLeave(&cs);
} 
  
// Method to merge sorted subarrays 
void merge(int a[], int l1, int h1, int h2) 
{ 
    // We can directly copy  the sorted elements 
    // in the final array, no need for a temporary 
    // sorted array. 
    int count=h2-l1+1; 
    int sorted[count]; 
    int i=l1, k=h1+1, m=0; 
    OsCriticalSectionEnter(&cs);
    while (i<=h1 && k<=h2) 
    { 
        if (a[i]<a[k]) 
            sorted[m++]=a[i++]; 
        else if (a[k]<a[i]) 
            sorted[m++]=a[k++]; 
        else if (a[i]==a[k]) 
        { 
            sorted[m++]=a[i++]; 
            sorted[m++]=a[k++]; 
        } 
    }
  
    while (i<=h1) 
        sorted[m++]=a[i++]; 
  
    while (k<=h2) 
        sorted[m++]=a[k++]; 
  
    for (i=0; i<count; i++,l1++) 
        a[l1] = sorted[i]; 
    OsCriticalSectionLeave(&cs);
} 
  
// To check if array is actually sorted or not 
void isSorted(int arr[], int len) 
{ 
    if (len==1) 
    { 
        printf("Sorting Done Successfully\n"); 
        return; 
    } 
  
    int i; 
    OsCriticalSectionEnter(&cs);
    for (i=1; i<len; i++) 
    { 
        if (arr[i]<arr[i-1]) 
        { 
            printf("Sorting Not Done\n"); 
            return; 
        } 
    } 
    OsCriticalSectionLeave(&cs);
    printf("Sorting Done Successfully\n"); 
    return; 
} 
  
// To fill randome values in array for testing 
// purpise 
void fillData(int a[], int len) 
{ 
    // Create random arrays 
    int i; 
    for (i=0; i<len; i++) 
        a[i] = rand(); 
    return; 
} 
  
// Driver code 
int main() 
{ 
    int shmid; 
    key_t key = IPC_PRIVATE; 
    int *shm_array; 
 
    thread_data ptr;  
    OsCriticalSectionCreate(&cs, "CS"); 
    // Using fixed size array.  We can uncomment 
    // below lines to take size from user 
    int length = LENGTH; 
  
    /* printf("Enter No of elements of Array:"); 
    scanf("%d",&length); */
  
    // Calculate segment length 
    size_t SHM_SIZE = sizeof(int)*length; 
    shm_array = (int *) malloc(SHM_SIZE); 
    // Create the segment. 
/*
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) 
    { 
        perror("shmget"); 
        _exit(1); 
    } 
 */
    // Now we attach the segment to our data space. 
/*
    if ((shm_array = shmat(shmid, NULL, 0)) == (int *) -1) 
    { 
        perror("shmat"); 
        _exit(1); 
    } 
*/
    // Create a random array of given length 
    srand(time(NULL)); 
    fillData(shm_array, length); 
    printf("Input array\n");
    for( int i =0; i < length; i++)
	printf("Array[%d] = %d\t", i, shm_array[i]);
    printf("\n"); 
 
    pthread_t pid;
    OsCriticalSectionEnter(&cs);
    printf("Thread id = %ld\t global_count = %d\n", pthread_self(), global);
    ptr.ptr = shm_array;
    global++;
    ptr.l = 0;
    ptr.h =length-1;
    pthread_create(&pid, NULL, mergeSort, (void *)&ptr);
    if (pid<0)
    {
        // Lchild proc not created 
        perror("Main Child Proc. not created\n");
        _exit(-1);
    }
    printf("Main Child Proc. created = %d\n", pid);
    OsCriticalSectionLeave(&cs);


    // Wait for child processes to finish 
//    waitpid(lpid, &status, 0); 
//    waitpid(rpid, &status, 0); 
      pthread_join(pid, NULL);


    // Sort the created array 
//    mergeSort_1(shm_array, 0, length-1); 
  
    // Check if array is sorted or not 
    isSorted(shm_array, length); 
  
    printf("Output array\n");
    for( int i =0; i < length; i++)
	printf("Array[%d] = %d\n", i, shm_array[i]);
    printf("\n"); 
    
    free(shm_array);
//    OsCriticalSectioniDelete(&cs);
    return 0; 
} 
