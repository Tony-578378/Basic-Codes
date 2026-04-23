#include <stdio.h>

int main(void)
{
    printf("sizeof('A') = %u\n", sizeof('A'));
    return 0;
}
/* Unlike in C where the result is 4, the value in C++ is 1. That's because 'A' is treated as int in C but char in C++. */