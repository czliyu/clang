/**************************************************
* File Name: exercise_5-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-06/11:51:00
**************************************************/

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
#define SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);

void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    } 
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c-'0');
    }
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }
    *pn *= sign/power;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main()
{
    int i = 0;
    int n, getfloat(float *);
    float array[SIZE];
    for (n=0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    while (array[i] != '\0') {
        printf("%f\n", array[i++]);
    }
    return 0;
}
