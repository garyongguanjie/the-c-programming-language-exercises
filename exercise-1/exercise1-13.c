#include <stdio.h>

// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. 
// It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging
#define MAX_LENGTH 20

int main()
{
    int c;
    int hist[MAX_LENGTH];
    int count = 0;

    for(int i=0;i<MAX_LENGTH;i++)
        hist[i]=0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t'){
            hist[count]++;
            count = 0;
        }else{
            count++;
        }
    }
    if (count>=0)
        hist[count]++;

    for(int i=1;i<MAX_LENGTH;i++){
        printf("%2d ",i);
        for(int j=0;j<hist[i];j++){
            putchar('|');
        }
        putchar('\n');
    }
}