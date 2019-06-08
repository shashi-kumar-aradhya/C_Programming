#include <stdbool.h>

int main()
{


bool f;         // conditional flag
unsigned int m; // the bit mask
unsigned int w; // the word to modify:  if (f) w |= m; else w &= ~m; 
f = true;
printf("f(true) = %d\n", f);
printf("-f = %d\n", -f);
f = false;
printf("f(false) = %d\n", f);
printf("-f = %d\n", -f);
//w ^= (-f ^ w) & m;
return 0;
}
