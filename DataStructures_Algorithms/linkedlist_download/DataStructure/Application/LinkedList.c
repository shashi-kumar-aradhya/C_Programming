#include <stdio.h>
#include <stdlib.h>
//#include "l_list.h"
#include "LinkedList.h"

#define SIZE 100000


//Element declaration
struct ele {
	LL ptr;			//Linked list pointer
	int value;		//Element is Anything 
};

int main() 
{
	int i = 0;
	int value = 0;
	LL *List_ptr = NULL;
	void *array[SIZE];
	struct ele *ptr =NULL;
	i = 0;

	
	while(i != SIZE) {
		array[i] = NULL;
		i++;
	}
	i = 0;
	while (i < SIZE) {		
		value = rand() % SIZE;
		if(!array[value]) {
			ptr = (struct ele *)malloc(sizeof(struct ele));
			ptr->value = value;
			array[value] = ptr;
			i++;
//			add_head(&List_ptr, &ptr->ptr);
			add_tail(&List_ptr, &ptr->ptr);
		}
	}
/*
	//For del_head and del_tail
	i = 0;
	while (i < SIZE) {		
		value = rand() % SIZE;
		if(array[value]) {
			del(&List_ptr, array[value]);
			free(array[value]);	
			i++;
		   	array[value] = NULL;
		}
	}
*/

	for (i = 0; i < SIZE; i++)
	{
		del_tail(&List_ptr);
		free(array[i]);
	}
	return 0;
}
