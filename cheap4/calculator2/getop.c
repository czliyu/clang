/**************************************************
* File Name: getop.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-26/08:59:23
**************************************************/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int _getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ;
    s[1] = '\0';
    printf("%c", c);
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))  
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) 
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getop(char s[])
{
    int i;
    static int c = 0; /* 哇偶，静态不会被重置 */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) 
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) 
            ;
    }
    s[i] = '\0'; 
    return NUMBER;
}
