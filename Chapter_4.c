/* 4.2 */
#include <stdio.h>

int main(void)
{
    int  j = 7;

    printf("%d\n", 3 < j < 5);  /* 1(True) gets printed, not 0(False). Because 3 < j < 5 is equivalent to (3 < j) < 5, and 3 < j means 3 < 7, which is true(1), so the whole expression is equivalent to 1 < 5, which is true(1). */
    return 0;
}
/* The correct way to write a test for 3 < j < 5: */
#include <stdio.h>

int main(void)
{
    int  j = 7;

    printf("%d\n", 3 < j && j < 5);/* 0 gets printed, as this expression is equivalent to (3 < j) && (j < 5). */
    return 0;
}

#include <stdio.h>

int main(void)
{
    double  x = 7e+33, y = 0.001;

    printf("%d\n", x < x + y);
    printf("%d\n", (x - (x + y)) < 0.0); /* Both 0s get printed instead of 1s. Because though mathematically the statements are true, x and x + y are equal in terms of machine accuracy. */
    return 0;
}

/* 4.4 */
#include <stdio.h>

int main(void)
{
    int  cnt = 0, c;
    while (++cnt <= 3 && (c = getchar()) != EOF) {
        printf("Character %d: %c\n", cnt, c);
    }
    return 0;
}
/* This is an example of a short-cut evaluation. If the length of the input is >= 3, then only the first 3 characters will be output, since the first expression holds. Otherwise, all characters will be output, since the second expression holds. */

/* 4.5 */
/* Compound statement */
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;
    
    if (a > 0) {
    a += b += c;
    printf("a = %d, b = %d, c = %d\n", a, b, c);/* a = 6, b = 5, c = 3 */
    }

    return 0;
}