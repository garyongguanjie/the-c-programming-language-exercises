#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

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
    x = 0b00101101101;
    p  = 6;
    n = 4;
    result = invert(x,p,n);
    printf("Result: 0x%X\n", result);


    printf("Testing right rot\n");
    x = 0b100001101;
    n = 4;
    result = rightrot(x,n);
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
    unsigned zero =  0;
    int mask1 = ~zero << (p+1-n);
    int mask2 = ~zero >> (32-p-1);
    // using xor here to invert the bits is kind of hard to figure out?
    return x ^ (mask1 & mask2);
}

// Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions
unsigned rightrot(unsigned x, int n){
    unsigned left = x << (32-n);
    return (x >> n) | left;
}
