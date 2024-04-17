#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char s[]);

int main(){
    char s[] = "0xEAB551";
    int x = htoi(s);
    printf("%X\n",x);
    return 0;
}

int htoi(char s[]){
    int len = strlen(s);
    int i = 0;
    if(len>=2 && s[1]=='x'){
        i = 2;
    }
    int x = 0;
    int e = 1;
    for(int j=len-1;j>=i;j--){
        if (isdigit(s[j])){
            x+=(s[j]-'0')*e;
        }else{
            x+=(s[j]-'A'+10)*e;
        }
        e*=16;
    }
    return x;
}