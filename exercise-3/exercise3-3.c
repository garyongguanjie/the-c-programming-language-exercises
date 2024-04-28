#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000
void expand(char s1[],char s2[]);

int main(){
    char s1[] = "a-z";
    char s2[MAX_LENGTH];
    expand(s1,s2);
    printf("%s\n",s2);

    char s11[] = "a-z0-9";
    expand(s11,s2);
    printf("%s\n",s2);

    char s12[] = "a-b-c";
    expand(s12,s2);
    printf("%s\n",s2);


    char s13[] = "-a-z";
    expand(s13,s2);
    printf("%s\n",s2);


    char s14[] = "-a-z0-9-";
    expand(s14,s2);
    printf("%s\n",s2);
    return 0;
}

// Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
// Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
// if there are double hypens take it literally

// s1 is source s2 expanded string
void expand(char s1[],char s2[]){
    int s1len,i,j,k;
    s1len = strlen(s1);
    i = 0;
    j = 0;
    
    for(i=0;i<s1len;i++,j++){
        if (i+1<s1len && i+2<s1len && s1[i]!='-' && s1[i+1]=='-' && s1[i+2]!='-'){
            // this is a range
            for(k=s1[i];k!=s1[i+2];k++,j++){
                s2[j] = k;
            }
            s2[j] = k;
            i = i + 2;
        }else{
            s2[j] = s1[i];
        }
    }
    s2[j] = s1[i];
}