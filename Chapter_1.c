#include<stdio.h>
int main()
{
    int a,b,sum;
    a = 1;
    b = 2;
    sum = a+b;
    printf("sum is %d\n", sum);
    return 0;
}
/* 1.2 */
#include <stdio.h>

int main(void)
{
    printf("from sea to shining C\n");
    return 0;
}

#include <stdio.h>

int main(void)
{
    printf("from sea to ");
    printf("shining C");
    printf("\n");
    return 0;
}

#include <stdio.h>

int main(void)
{
    printf("from sea\n");
    printf("to shining\nC\n");
    return 0;
}

#include <stdio.h>

int main(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("            ***********************\n");
    printf("            *  from sea           *\n");
    printf("            *  to shining C       *\n");
    printf("            ***********************\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
    return 0;
}

/* 1.3 */
/* The distance of a marathon in kilometers. */

#include <stdio.h>

int main(void)
{
    int     miles, yards;
    float   kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);/*1760.0 must be in double form or yards/1760 will be treated as an integer, which is 0 in this case.*/
    printf("\nA marathon is %f kilometers.\n\n ", kilometers);
    return 0;
}

/* 1.4 */
/* Measuring the Pacific Sea */

#include "pacific_sea.h" /* We have included stdio.h in pacific_sea.h, so we don't have to include it here. */

int main(void)
{
    const int  pacific_sea = AREA; /* In sq kilometers */
    double     acres, sq_miles, sq_feet, sq_inches;

    printf("\nThe Pacific Sea covers an area"); 
    printf(" of %d square kilometers.\n", pacific_sea); 
    sq_miles = SQ_MILES_PER_SQ_KILOMETER * pacific_sea; 
    sq_feet = SQ_FEET_PER_SQ_MILE * sq_miles; 
    sq_inches = SQ_INCHES_PER_SQ_FOOT * sq_feet; 
    acres = ACRES_PER_SQ_MILE * sq_miles; 
    printf("In other units of measure this is:\n\n"); 
    printf("%22.7e acres\n", acres); 
    printf("%22.7e square miles\n", sq_miles); 
    printf("%22.7e square feet\n", sq_feet); 
    printf("%22.7e square inches\n\n", sq_inches); /* 22 spaces in total from the left side, and 7 decimal places*/
    return 0;
}

/* 1.5 */
#include <stdio.h>

int main(void)
{
    
    char   c1, c2, c3;
    int    i;
    float  x;
    double y;

    printf("\n%s\n%s", "Input three characters,",
       "an int, a float, and a double: ");
    scanf("%c%c%c%d%f%lf", &c1, &c2, &c3, &i, &x, &y);
    printf("\nHere is the data that you typed in:\n");
    printf("%3c%3c%3c%5d%17e%17e\n\n", c1, c2, c3, i, x, y);
    return 0;
}

/* 1.6 */
/* while loop */
#include<stdio.h>

int main(void)
{
    int i = 1, sum = 0;

    while (i <= 5) {
        sum += i;
        ++i; /*equivalent to i = i + 1*/
    }
    printf("sum = %d\n", sum); /*sum = 1+2+3+4+5*/
    return 0;
}

/* if loop */
#include<stdio.h>

int main(void)
{
    int i = 1, a, b, c;

    if (i <= 5){
        a = 1;
        b = 2;
        c = 3;
    }
    else {
        a = -1;
        b = -2;
        c = -3;
    }
    printf("sum = %d\n", a + b + c); /*sum = 1+2+3+4+5*/
    return 0;
}

/* for loop */
#include<stdio.h>

int main(void)
{
    int i, sum = 0;

    for (i = 1; i <= 5; ++i){
        sum += i;
    }
    printf("sum = %d\n", sum); /*sum = 1+2+3+4+5*/
    return 0;
}
/* This is equicalent to the while loop example. */

/* Compute the minimum, maximum, sum and average. This program will be stored in running_sum.c*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int       i;
    double    x, min, max, sum, avg;

    if (scanf("%lf", &x) != 1) {
        printf("No data found - bye!\n");
        exit(1); /* Terminate the whole program immediately(1 != 0 means failure). */
    }

    min = max = sum = avg = x;
    printf("%5s%9s%9s%9s%12s%12s\n%5s%9s%9s%9s%12s%12s\n\n",
       "Count", "Item", "Min", "Max", "Sum", "Average",
       "-----", "----", "---", "---", "---", "-------");
    printf("%5d%9.1f%9.1f%9.1f%12.3f%12.3f\n",
       1, x, min, max, sum, avg); /* This is where i = 1 presented.*/

    for (i = 2; scanf("%lf", &x) == 1; ++i) {
        if (x < min)
         min = x;
        else if (x > max)
         max = x;
        sum += x;
        avg = sum / i;
        printf("%5d%9.1f%9.1f%9.1f%12.3f%12.3f\n",
         i, x, min, max, sum, avg);
    }
    return 0;
}

/* 1.7 */
#include <stdio.h>

float  maximum(float x, float y);
float  minimum(float x, float y);/* Actually we can exclude x and y at this moment, this just improves readibility. */
void   prn_info(void);

int main(void)
{
    int   i, n;
    float max, min, x;

    prn_info();
    printf("input n:  ");
    scanf("%d", &n);
    printf("\nInput %d real numbers:  ", n);
    scanf("%f", &x);
    max = min = x;
    for (i = 2; i <= n; ++i){
        scanf("%f", &x);
        max = maximum(max, x);
        min = minimum(min, x); /* The initial max and min here are the first value in x, then we compare them with the second, then third, etc, as the loop starts at i = 2. */
    }
    printf("\n%s%11.3f\n%s%11.3f\n\n",
       "Maximum value:", max,
       "Minimum value:", min);
    return 0;
}

float maximum(float x, float y)
{
    if (x > y)
       return x;
    else
       return y;
}

float minimum(float x, float y)
{
    if (x < y)
       return x;
    else
       return y;
}

void prn_info(void)
{
    printf("\n%s\n%s\n\n",
       "This program reads an integer value for n, and then",
       "processes n real numbers to find max and min values.");
}                                                              /* This function is included in our programme, so we do not nead return 0. */


#include <stdio.h>

int main(void)
{
    int a = 1;
    void try_to_change_it(int);

    printf("%d\n", a);/* a = 1 is printed. */
    try_to_change_it(a);/* a = 1 has been stored in the programme, what we redefined in the void function is just a copy of a. */
    printf("%d\n", a);/* a = 1 is printed again! */
    return 0;
}

void try_to_change_it(int a)
{
    a = 777;
}

/* 1.8 */
/* Arrays */
#include <stdio.h>
#define   CLASS_SIZE   5

int main(void)
{
    int  i, j, score[CLASS_SIZE], sum = 0, tmp;

    printf("Input %d scores:  ", CLASS_SIZE);
    for (i = 0; i < CLASS_SIZE; ++i) { /* When i reaches CLASS_SIZE - 1, there will be no further ++i. */
        scanf("%d", &score[i]);
        sum += score[i];
    }

    for (i = 0; i < CLASS_SIZE - 1; ++i)      /* bubble sort *//* Also, score[CLASS_SIZE-1] is the last element in the array, because the array starts from 0 rather than 1. */
       for (j = CLASS_SIZE - 1; j > i ; --j)
          if (score[j-1] < score[j]) {    /* check the order */
            tmp = score[j-1];
            score[j-1] = score[j];
            score[j] = tmp;  /* Each inner for loop append the largest value to the most left. */
          }
    printf("\nOrdered scores:\n\n");
    for (i = 0; i < CLASS_SIZE; ++i) 
       printf("  score[%d] =%5d\n", i, score[i]);
    printf("\n%18d%s\n%18.1f%s\n\n",
       sum, " is the sum of all the scores",
       (double) sum / CLASS_SIZE, " is the class average");
    return 0;
}
/* The above is the descending version, while the below is the ascending version. */
#include <stdio.h>
#define   CLASS_SIZE   5

int main(void)
{
    int  i, j, score[CLASS_SIZE], sum = 0, tmp;

    printf("Input %d scores:  ", CLASS_SIZE);
    for (i = 0; i < CLASS_SIZE; ++i) { 
        scanf("%d", &score[i]);
        sum += score[i];
    }

    for (i = 0; i < CLASS_SIZE - 1; ++i)      /* bubble sort */
       for (j = CLASS_SIZE - 1; j > i ; --j)
          if (score[j-1] > score[j]) {    /* check the order */
            tmp = score[j-1];
            score[j-1] = score[j];
            score[j] = tmp;
          }
    printf("\nOrdered scores:\n\n");
    for (i = 0; i < CLASS_SIZE; ++i) 
       printf("  score[%d] =%5d\n", i, score[i]);
    printf("\n%18d%s\n%18.1f%s\n\n",
       sum, " is the sum of all the scores",
       (double) sum / CLASS_SIZE, " is the class average");
    return 0;
}

/* Strings */
/* Have a nice day! */

#include <ctype.h>
#include <stdio.h>

#define  MAXSTRING  100
int main(void)
{
    char  c, name[MAXSTRING];
    int   i, sum = 0;

    printf("\nHi! What is your name? ");
    for (i = 0; (c = getchar()) != '\n'; ++i) {
        name[i] = c;
        if (isalpha(c))
         sum += c;
    }
    name[i] = '\0'; /* Use the null \0 as the end of the string.This is crucial for treating it as a valid C-style string. Now i has the value of i value in the end of the last for loop +1 */
    printf("\n%s%s%s\n%s",
       "Nice to meet you ", name, ".",
       "Your name spelled backwards is ");
    for (--i; i >= 0; --i) /* Initially i has the value of the index of \0 so --i automatically points to the end of the string \0, then \0 is putchar, then i - 1 to be the index of the last real character, then putchar, then go on until i = 0. */
       putchar(name[i]);
    printf("\n%s%d%s\n\n%s\n",
       "and the letters in your name sum to ", sum, ".",
       "Have a nice day!");
    return 0;
}

/* Pointers */
#include <stdio.h>
#include <string.h>

#define  MAXSTRING  100

int main(void)
{
    char  c = 'a', *p, s[MAXSTRING];

    p = &c;
    printf("%c%c%c  ", *p, *p + 1, *p + 2);
    strcpy(s, "ABC");
    printf("%s  %c%c%s\n", s, *s + 6, *s + 1, s + 1);/* s + 1 proceeds the pointer from s[0] to s[1]. */
    strcpy(s, "she sells sea shells by the seashore");
    p = s + 14;/* This points at s[14], which is the first character of the word "shells", this is equivalent to p = &s[14]. Also in this particular case, p = s + (15 or 16) is also equivalent. */
    for ( ; *p != '\0'; ++p) { /* The absence of the condition means there is no initial assignment. */
       if (*p == 'e')
          *p = 'E';
       if (*p == ' ')
          *p = '\n';
    }
    printf("%s\n", s);
    return 0;
}

/* 1.9 */
/* See the file cnt_letters.c. */

/* 1.10 */
/* See the file dbl_out.c*/

/* Exercises */
/* 2 */

#include <stdio.h>

int main(void)
{
    int     miles, yards;
    float   kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760);/*Yards/1760 is treated as an integer*/
    printf("\nA marathon is %f kilometers.\n\n ", kilometers);
    return 0;
}

/* 3 */
#include <stdio.h>

int main(void)
{
    double  miles, yards, kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %f kilometers.\n\n ", kilometers);/* Double can store more decimal places than float. */
    return 0;
}

/* 4 */
#include <stdio.h>

int main()
{
    printf("from sea to ");
    printf("shining C");
    printf("\n"); /* No complains deleting "void". */
    return 0;
}

#include <stdio.h>

int main()
{
    printf("from sea to ");
    printf("shining C");
    printf("\n"); /* For this one no complains further deleting return 0. This means my compiler needs a higher warning level. */
}

/* 5 */
#include <stdio.h> 
int main(void) 
{ 
    int x, y = 0; 
    x = 1 / y; 
    printf("x = %d\n", x); /* floating point exception */
    return 0; 
}

#include <stdio.h> 
int main(void) 
{ 
    int x = 0; 
    x = 1 / 0; 
    printf("x = %d\n", x); /* warning: division by zero is undefined */
    return 0; 
}

/* 6 */
#include <stdio.h> 
int main(void) 
{ 
    float x, y = 0; 
    x = 1 / y; 
    printf("x = %f\n", x); /* x = inf, good! */
    return 0; 
}

/* 7 */
int main(void)
{
    #include "pacific_sea.h" /* This is not allowed for my system. */
    const int  pacific_sea = AREA; /* In sq kilometers */
    double     acres, sq_miles, sq_feet, sq_inches;

    printf("\nThe Pacific Sea covers an area"); 
    printf(" of %d square kilometers.\n", pacific_sea); 
    sq_miles = SQ_MILES_PER_SQ_KILOMETER * pacific_sea; 
    sq_feet = SQ_FEET_PER_SQ_MILE * sq_miles; 
    sq_inches = SQ_INCHES_PER_SQ_FOOT * sq_feet; 
    acres = ACRES_PER_SQ_MILE * sq_miles; 
    printf("In other units of measure this is:\n\n"); 
    printf("%22.7e acres\n", acres); 
    printf("%22.7e square miles\n", sq_miles); 
    printf("%22.7e square feet\n", sq_feet); 
    printf("%22.7e square inches\n\n", sq_inches); /* 22 spaces in total from the left side, and 7 decimal places*/
    return 0;
}

/* 12 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int     i, i2, i3, i4, i5, x; 
    
    printf("input x: "); /* Input the value of x for how many lines you want. */
    if (scanf("%d", &x) != 1) {
        printf("No data found - bye!\n");
        exit(1); 
    }
    printf("\n  :::::  A TABLE OF POWERS  :::::\n\n");
    printf("%9s%9s%12s%12s%12s\n%9s%9s%12s%12s%12s\n", "Integer", "Square", "3rd power", "4th power", "5th power", "-------", "------", "---------", "---------",
       "---------");
    for (i = 1; i < x + 1; ++i) {
        i2 = pow(i, 2);
        i3 = pow(i, 3);
        i4 = pow(i, 4);
        i5 = pow(i, 5);
        printf("%9d%9d%12d%12d%12d\n", i, i2, i3, i4, i5);
    }
    return 0;
}

/* 16、17 */
/* See the file bavg.c */

/* 19 */
#include <stdio.h>

int main(void)
{
    int a1, a2, a3, cnt; 
    printf("Input three integers: "); 
    cnt = scanf("%d%d%d", &a1, &a2, &a3); 
    printf("Number of successful conversions: %d\n", cnt);/* Press Ctrl + D, which is an EOF combination for macOS, then an value of -1 will be produced. */
    return 0;
}

/* 20 */
#include <stdio.h>

int main(void)
{
    int cnt; 
    cnt = printf("abc abc"); 
    printf("\nNo. of characters printed: %d\n", cnt);/* 7 */
    return 0;
}

#include <stdio.h>

int main(void)
{
    int cnt; 
    cnt = printf("abc\nabc\n"); 
    printf("\nNo. of characters printed: %d\n", cnt);/* 8 */
    return 0;
}

#include <stdio.h>

int main(void)
{
    int cnt; 
    cnt = printf("abc\0abc\0"); 
    printf("\nNo. of characters printed: %d\n", cnt);/* 3 */
    return 0;
}

/* 21 */
#include <stdio.h>

int main(void)
{
    char c1, c2, c3;
    int  cnt; 
    printf("Input three characters: "); 
    cnt = scanf("%c%c%c", &c1, &c2, &c3); 
    printf("Number of successful conversions: %d\n", cnt);/* Always 3, except pressing Ctrl + D, which will produce -1. */
    return 0;
}

/* 22. See the file nletters.c */

/* 25 */
#include <stdio.h>
#include <string.h>

#define   MAXSTRING   100

void   prn_string(char *);

int main(void)
{
    char  s1[MAXSTRING], s2[MAXSTRING];

    strcpy(s1, "Mary, Mary, quite contrary,\n");
    strcpy(s2, "how does your garden grow?\n");
    prn_string(s1);
    prn_string(s1);
    strcat(s1, s2);       /* concatenate the strings */
    prn_string(s1);
    return 0;
}
void prn_string(char *s)
{
    while (*s != '\0') {
        putchar(*s);
        s++;
    }
}
/* or */
#include <stdio.h>
#include <string.h>

#define   MAXSTRING   100

void   prn_string(char *);

int main(void)
{
    char  s1[MAXSTRING], s2[MAXSTRING];

    strcpy(s1, "Mary, Mary, quite contrary,\n");
    strcpy(s2, "how does your garden grow?\n");
    prn_string(s1);
    prn_string(s1);
    strcat(s1, s2);       /* concatenate the strings */
    prn_string(s1);
    return 0;
}
void prn_string(char *s)
{
    for ( ;*s != '\0'; s++) {
        putchar(*s);
    }
}