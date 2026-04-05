#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    int  sum = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c))
            sum++;
    }

    printf("Number of letters: %d\n", sum);
    return 0;
}
/* I should put
cd "/Users/tony/Desktop/学校文件夹/UCL/4/Additional Reading/Programming"
gcc nletters.c -o nletters
./nletters < infile
in the terminal of my computer. Because the pseudo-shell of VScode does not handle < infile redirection properly, especially when your program reads until EOF.
That’s why it hangs or produces no output in VS Code, even though it works perfectly in a real terminal.*/
