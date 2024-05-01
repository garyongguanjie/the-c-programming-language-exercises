#include <stdio.h>

//Write versions of the library functions strncpy, strncat, and strncmp, 
// which operate on at most the first n characters of their argument strings. 
// For example, strncpy(s,t,n) copies at most n characters of t to s.


char *strncpy(char *s,char *ct,int n);
char *strncat(char *s,char *ct,int n);
int strncmp(char *cs,char *ct,int n);


int main(){
    char a[100] = "hellno";
    char b[] = "hellyeah";
    // char *c = strncat(a,b,10);
    // char *c = strncpy(a,b,4);

    int i = strncmp(a,b,5);
    printf("%d",i);


    return 0;
}


// char *strncpy(s,ct,n) copy at most n characters of string ct to s; return s. Pad with '\0''s if ct has fewer than n characters.
char *strncpy(char *s,char *ct,int n){
    char *sp = s;
    while(*ct && n){
        *s++ = *ct++;
        n--;
    }
    *s = '\0';
    while(n--)
        *s++='\0';
    return sp;
}


// char *strncat(s,ct,n) concatenate at most n characters of string ct to string s, terminate s with '\0'; return s.
char *strncat(char *s,char *ct,int n){
        char *sp = s;
    while(*s)
        s++;
    while(*ct && n){
        *s++ = *ct++;
        n--;
    }
    *s = '\0';
    return sp;
}

// int strncmp(cs,ct,n) compare at most n characters of string cs to string ct; return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct.
int strncmp(char *cs,char *ct,int n){
    for (;*cs && *ct && n;cs++,ct++,n--){
        if (*cs!=*ct){
            return cs>ct;
        }
    }
    return 0;
}