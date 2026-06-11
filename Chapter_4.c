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

/* 4.7 */
#include <stdio.h>

int main() {
    char c;
    int lc_cnt = 0;
    int other_cnt = 0;

    printf("Enter characters (then Ctrl+D to continue on Mac/Linux or Ctrl+Z on Windows):");

    while (scanf("%c", &c) != EOF) {

        if (c >= 'a' && c <= 'z')
            ++lc_cnt;
        else {
            ++other_cnt;
            printf("\n%c is not a lowercase letter\n", c);
        }
    }

    printf("\nNumber of lowercase letters: %d\n", lc_cnt);
    printf("Number of other characters: %d\n", other_cnt);

    return 0;
}

#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Enter a:");
    scanf("%d", &a);
    printf("Enter b:");
    scanf("%d", &b);
    if (a == 1)
       if (b == 2)
          printf("***\n");
    else                  /* This else statement still attaches to the nearest if, not the one in-line with it. */
       printf("###\n");
    
    return 0;
}

/* 4.10 */
/* Print a table of values for some boolean functions. */
#include <stdio.h>

int main(void)
{
    int  b1, b2, b3, b4, b5;         /* boolean variables */
    int  cnt = 0;

    printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n", /* headings */
       "Cnt", "b1", "b2", "b3", "b4", "b5",
       "fct1", "fct2", "majority");
    for (b1 = 0; b1 <= 1; ++b1)
       for (b2 = 0; b2 <= 1; ++b2)
          for (b3 = 0; b3 <= 1; ++b3)
             for (b4 = 0; b4 <= 1; ++b4)
                for (b5 = 0; b5 <= 1; ++b5)
                   printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
                      ++cnt, b1, b2, b3, b4, b5,
                      b1 || b3 || b5, b1 && b2 || b4 && b5,
                      b1 + b2 + b3 + b4 + b5 >= 3); /* all combinations of b1, b2, b3, b4, b5 = 0 or 1 get printed */
    putchar('\n'); /* add a new blank line */
    return 0;
}

/* 4.12 */
#include <stdio.h>

int main(void)
{
    int i, sum;
    i = 0;
    sum = 0;
    /* sum a series of integer inputs until 0 is input */
    do {
        sum += i;
        scanf("%d", &i);
    } while (i > 0);
    printf("Sum = %d\n", sum);
    return 0;
}

#include <stdio.h>

int main(void)
{
    int n, error;
    
    do {
        printf("Input a positive integer: ");
        scanf("%d", &n);
        if (error = (n <= 0))
           printf("\nERROR: Do it again!\n\n");
    } while (error);
    return 0;
}

/* A test that fails. */
#include <stdio.h>

int main(void)
{
    int     cnt = 0;
    double  sum = 0.0, x;

    for (x = 0.0; x != 9.9; x += 0.1) { /* trouble! infinite loop! */
        sum += x;
        printf("cnt = %5d\n", ++cnt);
    }
    printf("sum = %f\n", sum);
    return 0;
}

/* 4.13 */
/* Print Fibonacci numbers and quotients. */

#include <stdio.h>

#define   LIMIT   46

int main(void)
{
    long  f0 = 0, f1 = 1, n, temp;
    
    printf("%7s%19s%29s\n%7s%19s%29s\n%7s%19s%29s\n",
           /* headings */
       "  ", "Fibonacci", "Fibonacci",
       " n", "   number", " quotient",
       "--", "---------", "---------");
    printf("%7d%19d\n%7d%19d\n", 0, 0, 1, 1);  /* 1st 2 cases */
    for (n = 2; n <= LIMIT; ++n) {
       temp = f1;
       f1 += f0;
       f0 = temp;
       printf("%7ld%19ld%29.16f\n", n, f1, (double) f1 / f0);
    }
    return 0;
}

/* 4.14 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double  x;

    printf("Enter x: ");
    while (scanf("%lf", &x) == 1) {
        if (x < 0.0)
           goto negative_alert; /* The goto statement should be avoided in general. */
        printf("%f  %f\n", sqrt(x), sqrt(2 * x));
        printf("Enter x: ");
    }

    negative_alert: printf("Negative value encountered!\n");
    return 0;
}

/* 4.15 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double  x;

    printf("Enter x: ");
    while(1) {
        scanf("%lf", &x);
        if (x < 0.0)
           break;               /* exit loop if x is negative */
        printf("%f\n", sqrt(x));
    }
/* break jumps to here */
    return 0;
}

#include <stdio.h>
#define TOTAL 9

int main(void)
{
    int   i;
    char  c;

    printf("Enter c: ");
    for (i = 0; i < TOTAL; ++i) {
       c = getchar();
       if (c >= '0' && c <= '9')
          continue;
    printf("%c : %d\n", c, c);
                   /*  process other characters */
    /* continue transfers control to here to begin next iteration */
    }
    return 0;
}

/* 4.17 */
#include <stdio.h>

int main(void)
{
    int  x, y = 1, z = 3;

    x = (y < z) ? y : z; /* This assigns to x the minimum of y and z. */
    printf("%d\n", x);
}

/* Exercises */
/* 3 */
/* See the program read_char.c */

/* 5 */
/* This programme computes a 17% federal withholding tax and a 3% state withholding tax from salaries,
as well as the cumulative sums of all salaries and taxes. */
#include <stdio.h>

int main(void)
{
    double  salary;
    double  federalTax, stateTax;
    double  totalSalary = 0.0, totalFederalTax = 0.0, totalStateTax = 0.0;

    printf("Enter salaries (stop if non-numeric input):\n");

    while (scanf("%lf", &salary) ==1)
    {
        federalTax = salary * 0.17;
        stateTax = salary * 0.03;
        
        printf("Salary: %.2f, Federal Tax: %.2f, State Tax: %.2f\n",
               salary, federalTax, stateTax);

        totalSalary += salary;
        totalFederalTax += federalTax;
        totalStateTax += stateTax;
    }

    printf("\nTotals:\n");
    printf("Total Salaries     = %.2f\n", totalSalary);
    printf("Total Federal Tax  = %.2f\n", totalFederalTax);
    printf("Total State Tax    = %.2f\n", totalStateTax);

    return 0;
}