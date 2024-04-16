#include <stdio.h>

// Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
// assume characters are only 0-9 for now

int main()
{
    int c;
    int hist[10];

    for(int i=0;i<10;i++)
        hist[i]=0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            hist[c-'0']++;
    }

    for(int i=0;i<10;i++){
        printf("%2d ",i);
        for(int j=0;j<hist[i];j++){
            putchar('|');
        }
        putchar('\n');
    }
}