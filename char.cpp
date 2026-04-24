/* Chapter 3 */
/* 14 */
#include <stdio.h>

int main(void)
{
    printf("sizeof('A') = %u\n", sizeof('A'));
    return 0;
}
// Unlike in C where the result is 4, the value in C++ is 1. That's because 'A' is treated as int in C but char in C++.

/* 15 */
#include <stdio.h>

int main(void)
{
   char   c = 'A';

   printf("sizeof(c)       = %u\n", sizeof(c));        // 1, char
   printf("sizeof('A')     = %u\n", sizeof('A'));      // 1, chae
   printf("sizeof(c + c)   = %u\n", sizeof(c + c));    // 4, unsigned long
   printf("sizeof(c = 'A') = %u\n", sizeof(c = 'A'));  // 1, char

   return 0;
}