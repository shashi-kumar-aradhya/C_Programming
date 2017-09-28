#include <stdio.h>

int main()
{
   int *p_arr = (int *) malloc (10 * sizeof(int));
   if (NULL == p_arr) exit(0);
   printf ("11th integer:%d\n",p_arr[10]);
   p_arr[10]=10;
   free (p_arr);
   return 0;
}
