#include <stdio.h>
// Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */
int getline(char line[], int maxline);
int remove_trail(char rline[]);
/* print the longest input line */
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    while ((len = getline(line, MAXLINE)) > 0){
        if (remove_trail(line)>0){
            printf("%s",line);
        }
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

// not sure how to do this https://www.learntosolveit.com/cprogramming/chapter1/ex_1.18_remtrailbt
int remove_trail(char rline[]) {
    int i;

    for (i = 0; rline[i] != '\n'; ++i);
    --i; /* To consider raw line without \n */

    for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i); /* Removing the Trailing Blanks and Tab Spaces */

    if (i >= 0) /* Non Empty Line */
    {
        ++i;
        rline[i] = '\n';
        ++i;
        rline[i] = '\0';
    }
    return i;
}