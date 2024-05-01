#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char a[] = "hello world";
    char b[] = "orld";
    int i  = strend(a,b);
    printf("%d",i);
    return 0;
}

/* Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise. */
int strend(char *s, char *t)
{
    char *se = s;
    char *te = t;

    while (*se)
        se++;
        
    while (*te)
        te++;
    
    while(se>=s&&te>=t){
        if (*se!=*te)
            return 0;
        se--;te--;
    }
    return ++te==t;// is this alright???
}