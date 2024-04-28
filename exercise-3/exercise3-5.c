#include <stdio.h>
#include <string.h>

void itob(int n,char s[],int b);

int main(){
    char s[1000];
    int n = 999;
    itob(n,s,16);
    printf(s);
    return 0;
    return 0;
}

void itob(int n,char s[],int b){
    int i,r;
    unsigned un;
    
    if (n < 0) /* record sign */
        un = -n; /* make n positive */
    else
        un = n;

    i = 0;

    do{
        if((r = un%b)<=9){
            s[i++] = r + '0';
        }else{
            s[i++] = r - 10 + 'A';
        }
        
    }while((un/=b)>0);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    strrev(s);
}