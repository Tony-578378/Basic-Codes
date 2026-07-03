/* Chapter 4 Exercise 27 */
#include <stdio.h>

int main(void)
{
    int ch;
    int left_brace_cnt = 0, right_brace_cnt = 0;
    int left_paren_cnt = 0, right_paren_cnt = 0;
    int missing_brace, missing_paren, i;

    while ((ch = getchar()) != EOF) {
        putchar(ch);

        if (ch == '{') {
            left_brace_cnt++;
        }
        else if (ch == '}') {
            right_brace_cnt++;

            if (right_brace_cnt > left_brace_cnt) {
                printf("??");
            }
        }
        else if (ch == '(') {
            left_paren_cnt++;
        }
        else if (ch == ')') {
            right_paren_cnt++;

            if (right_paren_cnt > left_paren_cnt) {
                printf("??");
            }
        }
    }

    if (left_brace_cnt > right_brace_cnt) {
        missing_brace = left_brace_cnt - right_brace_cnt;

        printf("\nERROR: Missing right braces: ");

        for (i = 0; i < missing_brace; i++) {
            putchar('}');
        }

        putchar('\n');
    }

    if (left_paren_cnt > right_paren_cnt) {
        missing_paren = left_paren_cnt - right_paren_cnt;

        printf("\nERROR: Missing right parentheses: ");

        for (i = 0; i < missing_paren; i++) {
            putchar(')');
        }

        putchar('\n');
    }

    return 0;
}
/* Run gcc brace_check.c -o brace_check then ./brace_check < brace_test.c in the terminal if you are using VS code. */