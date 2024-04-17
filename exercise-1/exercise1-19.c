#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */
int getline(char line[], int maxline);
void reverse(char line[],int len);

/* print the longest input line */
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    while ((len = getline(line, MAXLINE)) > 0){
        reverse(line,len);
        printf("%s",line);
    }

    return 0;
}
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i=0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i < lim - 1){
            s[i] = c;
        }
        i++;
    }
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char line[],int len){
    if (len==0 || len==1){
        return;
    }
    int start = 0;
    int end = len-1;

    while(start<end){
        char temp = line[start];
        line[start] = line[end];
        line[end] = temp;
        start++;
        end--;
    }
}
