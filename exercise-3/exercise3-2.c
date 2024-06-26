#include <stdio.h>
#define MAX_LENGTH 100
void escape(char s[],char t[]);
void unescape(char s[],char t[]);

int main(){
    char t[] = "\t\nhello\t\nworld\n";
    char s[MAX_LENGTH];
    escape(s,t);
    printf("Testing escape\n");
    printf("%s\n",s);

    char t1[MAX_LENGTH];
    char s1[] = "hello\\tworld";

    unescape(s1,t1);
    printf("Testing unescape\n");
    printf("%s\n",t1);
    return 0;
}

// Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. 
// Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters
// s -> escaped string, t -> original string
void escape(char s[],char t[]){
    int i, j;
    char c;
    i = 0,j=0;
    for(;t[i]!='\0' && j<MAX_LENGTH;i++,j++){
        c = t[i];
        switch (c){
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = c;
                break;
        }
    }
    s[j] = '\0';
}


// s -> escaped string, t -> original string
void unescape(char s[],char t[]){
    int i,j;
    i = 0,j = 0;
    for(;s[i]!='\0';i++,j++){
        if(s[i]=='\\' & s[i+1]=='n'){
            t[i++] = '\n';
        }else if (s[i]=='\\' & s[i+1]=='t'){
            t[i++] = '\t';
        }else{
            t[j] = s[i];
        }
    }
    t[j] = '\0';
}