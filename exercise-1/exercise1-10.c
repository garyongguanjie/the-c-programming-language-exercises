#include <stdio.h>
/* count lines in input */
int main()
{
    int c;
    int numBlanks = 0;
    while ((c = getchar()) != EOF){
        if (c=='\t'){
            putchar('\\');
            putchar('t');
        }else if (c=='\b'){
            putchar('\\');
            putchar('b');
        }else if (c=='\\'){
            putchar('\\');
            putchar('\\');
        }else{
            putchar(c);
        }
    }
}