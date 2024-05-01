#include <stdio.h>

void strcat(char *s, char *t);

int main()
{
    char a[100] = "hello world";
    char b[] = " good bye";
    strcat(a,b);
    printf(a);
    return 0;
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t)
{
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}