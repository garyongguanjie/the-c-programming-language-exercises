#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char a[] = "123222334331";
    char b[] = "abc3";

    squeeze(a,b);
    printf("%s",a);

    return 0;
}

// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.


void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int hasMatch = 0;
    for (i = j = 0; s1[i] != '\0'; i++){
        for(k=0;s2[k]!='\0';k++){
            if(s1[i]==s2[k]){
                hasMatch = 1;
                break;
            }
        }
        if (!hasMatch)
            s1[j++] = s1[i];
        hasMatch = 0;
    }
    s1[j] = '\0';
}

// void squeeze(char s[], int c)
// {
//     int i, j;
//     for (i = j = 0; s[i] != '\0'; i++)
//         if (s[i] != c)
//             s[j++] = s[i];
//     s[j] = '\0';
// }