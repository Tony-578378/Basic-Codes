/* 3.1 */
#include <stdio.h>

int main(void)
{
    int    a, b, c;                 /* declaration */
    float  x, y = 3.3, z = -7.7;    /* declaration with 
                                    initialisations */

    printf("Input two integers: "); /* function call */
    scanf("%d%d", &b, &c);          /* function call */
    a = b + c;                      /* assignment */
    x = y + z;                      /* assignment */
    printf("%d%12f\n", a, x);
    return 0;
}

/* 3.3 */
#include <stdio.h>

int main(void)
{
    printf("%c", '\a'); /* bell rings */
    putchar('\a'); /* bell rings */
    printf("\abc\""); /* bc" is printed */
    printf("\"abc\""); /* "abc" is printed */
    printf("%cabc%c", '\'', '\''); /* 'abc' is printed */
    printf("%cabc%c", '\"', '"'); /* "abc" is printed */
    printf("\'abc'"); /* 'abc' is printed */
    printf("%cabc%c", '\"', '\''); /* "abc' is printed */
    return 0;
}

#include <stdio.h>

int main(void)
{
    char   c = 'a';

    printf("%c\n", c); /* a is printed */
    printf("%d\n", c); /* 97 is printed */
    printf("%c%c%c\n", c, c + 1, c + 2); /* abc is printed */
    return 0;
}

#include <stdio.h>

int main(void)
{
    char   c;
    int    i;

    for (i = 'a'; i <= 'z'; ++i)
       printf("%c", i);
    printf("\n");
    for (c = 65; c <= 90; ++c)
       printf("%c", c);
    printf("\n");
    for (c = '0'; c <= '9'; ++c)
       printf("%d", c);
    printf("\n");
    return 0;
}

/* 3.4 */
#include <stdio.h>

#define    BIG     2000000000 /* 2 billion */

int main(void)
{
    int  a, b = BIG, c = BIG;
    a = b + c;  /* out of range? */
    printf("%d", a); /* incorrect result */
    return 0;
}

/* 3.8 */
/* Compute the size of some fundamental types. */

#include <stdio.h>

int main(void)
{
    printf("The size of some fundamental types is computed.\n\n");
    printf("       char:%3u byte \n", sizeof(char)); /* 1 */
    printf("      short:%3u bytes \n", sizeof(short)); /* 2 */
    printf("        int:%3u bytes \n", sizeof(int)); /* 4 */
    printf("       long:%3u bytes \n", sizeof(long)); /* 8 */
    printf("   unsigned:%3u bytes \n", sizeof(unsigned)); /* 4 */
    printf("      float:%3u bytes \n", sizeof(float)); /* 4 */
    printf("     double:%3u bytes \n", sizeof(double)); /* 8 */
    printf("long double:%3u bytes \n", sizeof(long double)); /* 16 */
    printf("     signed:%3u bytes \n", sizeof(signed)); /* 4 */
    return 0;
}