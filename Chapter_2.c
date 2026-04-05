/* Insertion sort */
#include <stdio.h>
#define  CLASS_SIZE 6

int main(void)
{
    int i, j, x[CLASS_SIZE], token;

    printf("Input %d scores: ", CLASS_SIZE);
    for (i = 0; i < CLASS_SIZE; ++i) {
        scanf("%d", &x[i]);
    }

    for (i = 1; i < CLASS_SIZE; i++)
    {
        token = x[i];
        j = i-1;
        for (; j >= 0 && x[j] > token; j--)
        {
        x[j+1] = x[j];
        }
        x[j+1] = token;
    }
    printf("\nSorted array:\n\n");
    for (i = 0; i < CLASS_SIZE; i++)
    {
        printf("   x[%d] = %5d\n", i, x[i]);
    }
    return 0;
}
/* 2.1 */
/* Read in two integers and print their sum. */
#include  <stdio.h>

int main(void)
{
    int  a, b, sum;
    
    printf("Input two integers: ");
    scanf("%d%d", &a, &b);
    sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);
    return 0;
}

/* 2.3 */
/*****************************
*   If you wish, you can     *
*   put comments in a box.   *
*****************************/

// This is a comment in C++./* This C++ style comment does not cause an error in C for the latest C99 standard. See the file comment.cpp. */

/* This comment style mimics the
// previous C++ comment style.
*/

/* 2.7 */
/* Some examples of strings */
// "/* this is not a comment */" //
// "a string with double quotes \" within" //
// "a single backslash \\ is in this string" //

/* 2.10 */
#include <stdio.h>

int main(void)
{
    int a, b, c = 0;
    
    a = ++c;
    b = c++;
    printf("%d %d %d\n", a, b, ++c); /* 1 1 3 is printed */
    return 0;
}

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;
    
    printf("%d\n", ++ a * b - c --); /* 1 is printed. The "post" in postfix means the decrement happens after the current expression is evaluated. c becomes 2 after the calculation. It now still equals to 3. */
    return 0;
}

/* 2.12 */
/* Some powers of 2 are printed. */

#include <stdio.h>

int main(void)
{
    int i = 0, power = 1;

    while (++i <= 10) {
        printf("%-6d", power *= 2); /* - is the Left-alignment.By default, C justifies text to the right. The minus sign forces the output to align to the left within the specified width. */
    }
    printf("\n");
    return 0;
}

/* 2.13 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;

    printf("\n%s\n%s",
       "Some randomly ditributed integers will be printed.",
       "How many do you want to see? ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        if (i % 10 == 0) {
            putchar('\n');
        }
        printf("%12d", rand());/* The VS code narrows the spaces, thus I have to use 12 instead of 7. */
    }
    printf("\n\n");
    return 0;
}

/* 14 */
#include <stdio.h>

int main(void)
{
    int a, b = 0, c = 0;

    a = ++b + ++c;/* 1 + 1, 1 + 0, 1 + 0 */
    printf("%d %d %d\n", a, b, c);
    a = b++ + c++;/* 1 + 1, 1 + 1, 1 + 1 */
    printf("%d %d %d\n", a, b, c);
    a = ++b + c++;/* 3 + 2, 1 + 2, 2 + 1 */
    printf("%d %d %d\n", a, b, c);
    a = b-- + --c;/* 3 + 2, 3 - 1, -1 + 3 */
    printf("%d %d %d\n", a, b, c);

    return 0;
}

/* 29 */
#inc\
lude <stdio.h>

int mai\
n(void)
{
    printf("Will this work?\n");
    ret\
urn 0;
}
/* It works! */

/* 30 */
#incl <stdixx.h> /* two errors on this line */
/* ^ tempCodeRunnerFile.c:5:5: error: call to undeclared library function 'printf' with type 'int (const char *, ...)'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration] */
int main(void)
{
    printf("Try me.\n"); /*tempCodeRunnerFile.c:5:5: note: include the header <stdio.h> or explicitly provide a declaration for 'printf' */
    return 0;
}

#include <stdixx.h> /* tempCodeRunnerFile.c:1:10: fatal error: 'stdixx.h' file not found */

int main(void)
{
    printf("Try me.\n"); 
    return 0;
}