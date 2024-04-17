#include <stdio.h>

// Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.

int any(char s1[], char s2[]);

int main(){

    char a[] = "hello world";
    char b[] = "qqqqqqqwsss";
    printf("%d",any(a,b));
    return 0;
}

int any(char s1[], char s2[]){
    int i,j;
    for(i=0;s1[i]!='\0';i++){
        for(j=0;s2[j]!='\0';j++){
            if (s1[i]==s2[j]){
                return i;
            }
        }
    }
    return -1;
}