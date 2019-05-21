#include <stdio.h>


void printbits(unsigned int value)
{
        int i = sizeof(char ) * 8 - 1;
        for (; i >= 0; i--) {
                if ( value & (1 << i))
                        printf("1");
                else
                        printf("0");
        }
        return;
}

