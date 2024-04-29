#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(){
    char s[] = "zzabcabczz";
    char t[] = "abc";
    int i = strindex(s,t);
    printf("%d",i);

    return 0;
}

//Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
int strindex(char s[], char t[])
{
    int i, j, k, slen;
    slen = strlen(s);

    for (i = slen-1; s[i]>=0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}