#include <stdio.h>

int bitcount(unsigned x);

int main()
{


    unsigned x = 0b1000100010110;
    printf("bitcount: %d",bitcount(x));
    return 0;
}

/* bitcount: count 1 bits in x */
// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. 
// all bits to the right of the rightmost 1bit will be come 1, & itself will change it to all zero.
// Use this observation to write a faster version of bitcount.
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        if (x != 0)
            b++;
    return b;
}