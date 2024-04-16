#include <stdio.h>
/* count lines in input */
int main()
{
    int c;
    int numBlanks = 0;
    while ((c = getchar()) != EOF){
        if (c==' '){
            if (numBlanks==0){
                numBlanks++;
                putchar(c);
            }
        }else{
            numBlanks = 0;
            putchar(c);
        }
    }
}