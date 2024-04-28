#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);

int main(){
    char s[1000];
    int n = INT_MIN;
    itoa(n,s);
    printf(s);
    return 0;
}

/* itoa: convert n to characters in s */

//In a two's complement number representation, our version of itoa does not handle the largest negative number,
// that is, the value of n equal to -(2wordsize-1). 
// Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
void itoa(int n, char s[])
{
    int i, sign;
    unsigned un;
    if ((sign = n) < 0) /* record sign */
        un = -n;         /* make n positive */
    i = 0;
    do
    {                          /* generate digits in reverse order */
        s[i++] = un % 10 + '0'; /* get next digit */
    } while ((un /= 10) > 0);   /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}