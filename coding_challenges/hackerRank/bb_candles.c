#include <stdio.h>
#include <stdlib.h>

int b(int n, int a, int *ar)
{
    int count = 0, max = 0;
    int i;
    for(i=0; i < n; i++)
    {
        if (ar[i] >= max) {
            if (ar[i] == max)
                count++;
            else {
                max = ar[i];
                count = 1;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int *ar = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int result = b(n,n,ar);
    printf("res = %d\n", result);
    return 0;
}

