/**************************************************
* File Name: getint.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-04/12:21:49
**************************************************/

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
#define SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

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
    int n, array[SIZE], getint(int *); 
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    while (array[i] != '\0') {
       printf("%d\n", array[i]);
       i++;
    }
    printf("%d\n", array[i]);
}
