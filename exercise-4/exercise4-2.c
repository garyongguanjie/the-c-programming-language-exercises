#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{   
    char s[] = "11.234e-2";
    printf("%f",atof(s));
    return 0;
}

/* atof: convert string s to double */
// Extend atof to handle scientific notation of the form
// 123.45e-6 
// where a floating-point number may be followed by e or E and an optionally signed exponent.
double atof(char s[])
{
    double val, power, d;
    int i, sign, exp;
    exp = 0;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i]=='e' || s[i]=='E'){
        i+=2;
        for(;isdigit(s[i]);i++){
            exp = 10 * exp + (s[i] - '0');
        }
    }

    d = sign * val / power;

    for (;exp>0;exp--){
        d*=10;
    }
    return d;
}