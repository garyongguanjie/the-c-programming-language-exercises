#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 100000
#define MAXLINES 1000
#define MAXLENGTH 1000

char buffer[BUFFERSIZE];
char *nlineb[MAXLINES];

int main(int argc, char *argv[])
{
    int n = 10;
    if (argc == 3)
    {
        if (*argv[1] == '-' && *++argv[1] == 'n')
        {
            n = atoi(argv[2]);
        }
        if (n >= MAXLINES)
        {
            printf("MAXLINES exceeded\n");
            return 1;
        }
    }

    char linebuffer[MAXLENGTH];

    char *b0 = buffer; //buffer 0 pointer
    char *brp = buffer; // buffer read pointer
    char *bwp = buffer; // buffer write pointer
    char *bep = &buffer[BUFFERSIZE-1]; // buffer end pointer

    int ls = 0;
    int nlines = 0;
    int len = 0;

    while (getline(linebuffer, MAXLENGTH))
    {
        // free pointers if we are at nlines;
        if (nlines>=n){
            brp = nlineb[(ls+1)%n];
            nlines--;
        }
        len = strlen(linebuffer)+1; // include '\0' character
        if (len<=bep-bwp+1){
            strcpy(bwp,linebuffer);
            nlineb[ls] = bwp;
            bwp = bwp+len;
        }else if(len<=brp-b0){
            str(b0,linebuffer);
            nlineb[ls] = b0;
            bwp = b0 + len;
        }else{
            printf("No space...\n");
        }
        ls++;
        ls%=n;
        nlines++;
    }

    // print the remaining lines;
    for (;ls%n!=0;ls++){
        printf(nlineb[ls]);
    }
}

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}