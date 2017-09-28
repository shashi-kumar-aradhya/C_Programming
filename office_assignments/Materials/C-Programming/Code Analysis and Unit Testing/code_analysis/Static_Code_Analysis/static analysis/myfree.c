#include <stdio.h>
/*@only@*/ /*@null@*/ void * mymalloc(size_t size);
void myfree(/*@only@*/ /*@out@*/ void *ptr);

int main()
{
   int *p = (int *) mymalloc (sizeof(int)*10);
   myfree (p);
   return 0;
}
