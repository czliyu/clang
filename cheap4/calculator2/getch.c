/**************************************************
* File Name: getch.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-26/09:11:40
**************************************************/

#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[bufp--] : getchar();;
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
