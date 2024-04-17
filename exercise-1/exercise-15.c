#include <stdio.h>

float convertFtoC(float fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahr = lower;
    printf("Fahrenheit Celsius\n");
    while (fahr <= upper)
    {
        celsius = convertFtoC(fahr);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float convertFtoC(float fahr){
    return (5.0 / 9.0) * (fahr - 32.0);
}