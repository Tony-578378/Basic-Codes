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

/* 3.9 */
#include <stdio.h>

#define  EOF   (-1)

int main(void)
{
    int  c;

    while ((c = getchar()) != EOF) { /* input something/enter Ctrl + C to terminate */
        putchar(c);
        putchar(c);
    }
    return 0;
}

#include <stdio.h>

int main(void)
{
    int  c;

    while ((c = getchar()) != EOF)
       if (c >= 'a' && c <= 'z')
          putchar(c + 'A' - 'a');
       else putchar(c);

    return 0;
}

/* 3.10 */
#include <math.h>
#include <stdio.h>

int main(void)
{
    double  x;

    printf("\n%s",
       "The following will be printed:\n"
       "\n"
       "   the square root of x\n"
       "   x raised to the power x\n"
       "\n");

    while (1) {       /* while TRUE */
       printf("Input x: ");
       if (scanf("%lf", &x) != 1)
          break;
       if (x >= 0.0)
          printf("%15s%22.15e\n%15s%22.15e\n%15s%22.15e\n\n",
             "x = ", x,
             "sqrt(x) = ", sqrt(x),
             "pow(x, x) = ", pow(x, x));
       else {
          printf("\nSorry, your number must be nonnegative.\n");
          break;
       }
    }

    printf("\nBye!\n\n");
       return 0;
}

/* 3.11 */
#include <stdio.h>

int main(void)
{
   char   c = 'A'; /* integral ptomotion from char to int */

   printf("%c\n", c);
   printf("%d\n", c);
   return 0;
}

/* 3.12 */
/* Decimal, hexadecimal, octal conversions. */
#include <stdio.h>

int main(void)
{
   printf("%d  %x  %o\n", 19, 19, 19); /* 19 13 23 */
   printf("%d  %x  %o\n", 0x1c, 0x1c, 0x1c); /* 28 1c 34 */
   printf("%d  %x  %o\n", 017, 017, 017); /* 15 f 17 */
   printf("%d\n", 11 + 0x11 + 011); /* 11 + 17 + 9 = 37 */
   printf("%x\n", 2097151); /* 1fffff */
   printf("%d\n", 0x1FfFFf); /* 2097151 */
   return 0;
}

/* 1 */
#include <stdio.h>

int main(void)
{
   double  x = 123.45123451234512345;
   double  y = 123.45123451234512300; /* last two digits zero */

   printf("%.17f\n%.17f\n", x, y);
   return 0;
}

#include <stdio.h>

int main(void)
{
   double  x = 123.45123451234512345;
   double  y = 123.45123451234510000; /* last four digits zero */

   printf("%.17f\n%.17f\n", x, y); /* different results */
   return 0;
}

#include <stdio.h>

int main(void)
{
   double  x = 123.45123451234512345;
   double  y = 123.45123451234512000; /* last three digits zero */

   printf("%.17f\n%.17f\n", x, y);
   return 0;
}
/* The initialiser for y must end with 4 zeros to get different numbers printed. Because a double stores 15 significant digits,
and the digits beyond this cannot be stored properly. 3 digits of difference is still non-significant to make a difference while 4 digits are enough. */