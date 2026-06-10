/* Chapter 4 Exercise 3 */
#include <stdio.h>

int main(void)
{
    int  digit_cnt = 0, other_cnt = 0, c;

    while ((c = getchar()) != EOF)
       if (c >= '0' && c <= '9')
          ++digit_cnt;
       else
          ++other_cnt;
       printf("%10s%20s\n\n", "digits", "other characters");
       printf("%10d%20d\n\n", digit_cnt, other_cnt);

    return 0;
}
/* Type gcc read_char.c -o read_char then ./read_char < read_char in the terminal. */