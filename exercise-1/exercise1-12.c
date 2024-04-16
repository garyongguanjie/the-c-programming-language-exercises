// Write a program that prints its input one word per line.

#include <stdio.h>

int main()
{
    int c,count=0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t'){
            if (count==0){
                putchar('\n');
            }
            count++;
        }else{
            count = 0;
        }
        if (count==0){
            putchar(c);
        }
        
    }
}