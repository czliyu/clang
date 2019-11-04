/**************************************************
* File Name: day.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-29/16:01:40
**************************************************/

#include <stdio.h>

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    int *p;
    if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) {
        printf("incurrent args number"); 
        return -1;
    }
    leap = (year%4 == 0) && ((year%100 != 0) || (year%400 == 0));
    p = daytab[leap];
    for (i = 1; i < month; i++)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    int *p;
    leap = (year%4 == 0) && ((year%100 != 0) || (year%400 == 0));
    p = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - daytab[leap];
    *pday = yearday;
}

int main()
{
    int m, d;
    printf("%d\n", day_of_year(1994, 4, 16)); 
    month_day(1994, 124, &m, &d);
    printf("%d\t%d\n", m, d);
    return 0;
}
