#include<stdio.h>
#define MYSIZEOF(X) ((X*)0 +1)
int main()
{
    printf("%ld", MYSIZEOF(int));
    return 0;
}


