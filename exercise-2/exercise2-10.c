#include <stdio.h>

int lower(int c);

int main()
{
    for(char c = 'A';c<='Z';c++){
        putchar(lower(c));
    }
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c+'a'-'A' : c;
}