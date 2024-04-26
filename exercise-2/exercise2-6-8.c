#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned invert(unsigned x, int p, int n);

int main()
{
    printf("Testing get bits\n");
    unsigned int x = 0xFF;  
    int p = 8; 
    int n = 2;

    unsigned result = getbits(x, p, n);
    printf("Result: 0x%X\n", result);

    printf("Testing set bits\n");
    x = 0b1000000;
    p  = 0;
    n = 1;
    int y = 0b1;
    result = setbits(x,p,n,y);
    printf("Result: 0x%X\n", result);


    printf("Testing invert bits\n");
    x = 0b1000000;
    p  = 0;
    n = 1;
    result = invert(x,p,n);
    printf("Result: 0x%X\n", result);
    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

// returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, int y)
{
    // get the rightmost n bits of y
    // shift it to the correct position leaving all other positions as 0
    // bitwise or with
    return ((y & ~(~0 << n)) << (p+1-n)) | x;
}

// returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
unsigned invert(unsigned x, int p, int n){
    
}