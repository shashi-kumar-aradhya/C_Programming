#include<stdio.h>

static inline __attribute__((always_inline)) void print_till_zero(int x)
{
        printf("\n Value of x : %d", x);
//        if(x > 0)
//                print_till_zero(x-1);
}
int main()
{
        print_till_zero(100);
	return 0;
} 
