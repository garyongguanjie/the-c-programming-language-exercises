#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    celsius = lower;
    printf("Celsius Fahrenheit\n");
    while (celsius <= upper)
    {
        fahr =  (celsius * 9 / 5)+32;
        printf("%10.0f %7.1f\n",celsius, fahr);
        celsius = celsius + step;
    }
}