#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getline(char *s, int lim);
int atoi(char *s);
void reverse(char *s);

int main()
{
    // char a[MAXLINE];
    // int b;
    // while ((b = getline(a, MAXLINE)))
    // {
    //     printf("%s\n", a);
    //     printf("%d", b);
    // }
    // int a = atoi("1239");
    // printf("%d\n",a);

    char a[] = "hello world";
    reverse(a);
    printf(a);
    return 0;
}

/* getline: get line into s, return length */
int getline(char *s, int lim)
{
    char *si = s;
    int c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - si;
}

/* atoi: convert s to integer; version 2 */
int atoi(char *s)
{
    int i, n, sign;
    for (i = 0; isspace(*s); s++) /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') /* skip sign */
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    char *se = s;
    char temp;
    while (*se)
        se++;
    se--;
    for (; s < se; s++, se--)
    {
        temp = *s;
        *s = *se;
        *se = temp;
    }
}