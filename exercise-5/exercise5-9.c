#include <stdio.h>

// Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(){
    int doy = day_of_year(2024,5,4);
    int month,day;
    month_day(2024,doy,&month,&day);
    printf("%d",day);

    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *p = &daytab[leap][1];
    for (i = 1; i < month; i++)
        day += *p++;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *p = &daytab[leap][1];
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *p--;
    *pmonth = i;
    *pday = yearday;
}