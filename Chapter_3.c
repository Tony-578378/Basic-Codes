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

/* 2 */
/* Test whether sin^2(x) + cos^2(x) = 1 holds. */
#include <math.h>
#include <stdio.h>

int main(void)
{
   double   two_pi = 2.0 * M_PI;   /* in math.h */
   double   h      = 0.1;          /* step size */
   double   x;

   for (x = 0.0; x < two_pi; x += h)
      printf("%5.1f: %.15e\n",     /* e means in exponential form */
         x, sin(x) * sin(x) + cos(x) * cos(x));
      return 0;
}
/* It approximately holds. */
/* Now change %.15e to %.15f. */
#include <math.h>
#include <stdio.h>

int main(void)
{
   double   two_pi = 2.0 * M_PI;
   double   h      = 0.1;
   double   x;

   for (x = 0.0; x < two_pi; x += h)
      printf("%5.1f: %.15f\n",
         x, sin(x) * sin(x) + cos(x) * cos(x));
      return 0;
}
/* It perfectly holds. Because a float stores fewer digits than an exponential number. */

/* 3 */
/* A table of trigonometric values for sin(), cos(), and tan(). The angles in the table go from 0 to 2*pi in 20 steps.*/
#include <math.h>
#include <stdio.h>

int main(void)
{
   double   two_pi = 2.0 * M_PI;
   double   h      = M_PI/10.0; /* step size */
   double   x;

   for (x = 0.0; x < two_pi; x += h)
      printf("sinx: %.15f cosx: %.15f tanx: %.15f\n",
         sin(x), cos(x), tan(x));
   return 0;
}

/* 6 */
#include <stdio.h>

int main(void)
{
   int   big_big = 2000000000 + 2000000000 ;

   printf("%d   %u\n", big_big, big_big);
   return 0;
}
/* The output is -294967296 with type "int" but the correct 4000000000 with type "unsigned". Because although both "int" and "unsigned"
are 4-byte, an "int" allows negative values but an "unsigned" does not, so the answer overflows for an "int" but not for an "unsigned". */

/* 8 */
/* Find the value of "epsilon" in my machine. */
/* start with 1e-37 */
#include <stdio.h>

int main(void)
{
   double  eps = 1e-37;

   if (1.0 < 1.0 + eps)
       printf("True\n");
   else
       printf("False\n");
   
   return 0;
}
/* It is false. */
/* Now find the true value of eps. */
#include <stdio.h>

int main(void)
{
   double  eps = 1.0;

   /* Keep dividing by 2 until 1.0 + eps is no longer greater than 1.0. */
   while (1.0 + eps > 1.0) {
      eps = eps / 2.0;
   }
   eps = eps * 2.0; /* The last one is too small so double it. */
   printf("The value of epsilon in my machine is %.20e\n", eps);
   return 0;
}
/* It is about 2.22044604925031308085e-16. */

/* 9 */
#include <math.h>
#include <stdio.h>

double   f(double x);

int main(void)
{
   double   x;

   for (x = -0.25; x <= +0.25; x += 0.01)
      printf("f(%+.2f) = %+.15f\n", x, f(x));
   return 0;
}

double f(double x)
{
   return (tan(sin(x)) - sin(tan(x)));
}
/* The results are almost 0, which means the difference between tan(sin(x)) and sin(tan(x)) is very flat. 
This can be reflected that the first 7 terms of their Taylor expansions agree. */

/* 10 */
#include <stdio.h>

int main(void)
{
   char           c = -1;
   signed char    s = -1;
   unsigned char  u = -1;

   printf("c = %d  s = %d  u = %d\n", c, s, u);
   return 0;
}
/* c = -1  s = -1  u = 255 */
/* So a plain char is treated as signed. */
/* Then try
gcc -funsigned-char program.c -o program
./program */
/* There could be such a programme in some ANSI C compilers, which can change a plain char to an unsigned char, but not in VS code.*/

/* 14 */
#include <stdio.h>

int main(void)
{
   printf("sizeof('A') = %u\n", sizeof('A'));
   return 0;
}
/* warning: format specifies type 'unsigned int' but the argument has type 'unsigned long' */
/* The value is 4. */
/* See the file char.cpp to compare the patterns of C and C++. */

/* 15 */
#include <stdio.h>

int main(void)
{
   char   c = 'A';

   printf("sizeof(c)       = %u\n", sizeof(c));        /* 1, char */
   printf("sizeof('A')     = %u\n", sizeof('A'));      /* 4, unsigned long */
   printf("sizeof(c + c)   = %u\n", sizeof(c + c));    /* 4, unsigned long */
   printf("sizeof(c = 'A') = %u\n", sizeof(c = 'A'));  /* 1, char, because 'A' has been defined to be a char, c */

   return 0;
}

/* 16 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
   printf("Minimum value of unsigned long stored in my system: %lu\n", 0UL);       /* 0 */
   printf("Maximum value of unsigned long stored in my system: %lu\n", ULONG_MAX); /* 18446744073709551615 */

   return 0;
}

/* 17 */
#include <limits.h>         /* for UNIT_MAX */
#include <stdio.h>

int main(void)
{
   int        i;
   unsigned   u = UINT_MAX; /* typically 4294967295 or 65535 */

   for (i = 0; i < 10; ++i)
      printf("%u + %d = %u\n", u, i, u + i);
   for (i = 0; i < 10; ++i)
      printf("%u * %d = %u\n", u, i, u * i);
   return 0;
}
/* 4294967295 + 0 = 4294967295
4294967295 + 1 = 0
4294967295 + 2 = 1
4294967295 + 3 = 2
4294967295 + 4 = 3
4294967295 + 5 = 4
4294967295 + 6 = 5
4294967295 + 7 = 6
4294967295 + 8 = 7
4294967295 + 9 = 8
4294967295 * 0 = 0
4294967295 * 1 = 4294967295
4294967295 * 2 = 4294967294
4294967295 * 3 = 4294967293
4294967295 * 4 = 4294967292
4294967295 * 5 = 4294967291
4294967295 * 6 = 4294967290
4294967295 * 7 = 4294967289
4294967295 * 8 = 4294967288
4294967295 * 9 = 4294967287 */
/* For unsigned int, C uses arithmetic modulo: UINT_MAX + 1 wraps around to 0. If UINT_MAX = 4294967295, 
then arithmetic is modulo: 4294967296. For multiplication, UINT_MAX = -1 mod 4294967296 = 4294967295, 
UINT_MAX * 2 = -2 mod 4294967296 = 4294967294, etc. */

/* 18 */
#include <stdio.h>

int main(void)
{
   double  x = 1e+307;              /* big */
   double  y = x * x;               /* too big! */

   printf("x = %e  y = %e\n", x, y); /* x = 1.000000e+307  y = inf */
   return 0;
}