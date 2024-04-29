// Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
int getop(char[]);
void push(double);
double pop(void);
void print_stack_top();
void duplicate_top();
void swap_two();
void handlemath();

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            // 4-3
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(),op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case 'a':
            print_stack_top();
            break;
        case 'b':
            duplicate_top();
            break;
        case 'c':
            swap_two();
            break;
        case 'd':
            handlemath(s);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_stack_top(){
    if(sp>=1){
        printf("stack top:%d",val[sp-1]);
    }else{
        printf("stack is empty cannot print top");
    }
}

void duplicate_top(){
    if(sp>=1){
        val[sp] = val[sp-1];
        sp++;
    }else{
        printf("stack is empty cannot duplicate top");
    }
}

void swap_two(){
    int temp;
    if(sp>=2){
        printf("swapping...\n");
        temp = val[sp-2];
        val[sp-2] = val[sp-1];
        val[sp-1] = temp;
    }else{
        printf("stack has less then 2 values cannot swap");
    }
}


#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
// use n to denote negative numbers
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
        return c; /* not a number */
    i = 0;
    if (c=='-'){
        if (!isdigit(s[++i] = c = getch())){
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    // collect trigo names
    if (isalpha(c)){
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return 'd';
    }
    
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void handlemath(char s[]){
    int exponent;
    if (strcmp(s,"sin")==0){
        push(sin(pop()));
    }
    else if (strcmp(s,"exp")==0){
        push(exp(pop()));
    }
    else if (strcmp(s,"pow")==0){
        exponent = pop();
        push(pow(pop(),exponent));
    }
}