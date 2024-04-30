#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int c);
int getfloat(float *pn);

int main(){

    int n;
    float array[SIZE];
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    
    for(n=0;n<SIZE;n++)
        printf("%f,",array[n]);

    return 0;
}


/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
    float c, sign, power;
    power = 1.0;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c))
        return 0;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c=='.'){
        c = getch();
        for (; isdigit(c); c = getch()){
            *pn = 10 * *pn + (c - '0');
            power*=10;
        }

    }
        
    *pn *= sign;
    *pn /= power;
    
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}