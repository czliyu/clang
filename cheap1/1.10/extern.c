/**************************************************
* File Name: extern.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-27/09:14:54
**************************************************/

#include <stdio.h>

#define MAXLINE 100

int _getline(void);

void copy(void);

char longest[MAXLINE], line[MAXLINE];
int main()
{
    int len, max;

    extern char longest[MAXLINE];

    max = 0;
    while ((len = _getline()) > 0) {
        if (len > max) {
            max = len;
            copy(); 
        }
    } 
    if (max > 0)
        printf("%s", longest);
    return 0;
}


int _getline(void)
{
    int c, i;
    extern char line[MAXLINE];

    for (i=0;i<MAXLINE-1 && (c = getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i; 
    }
    line[i] = '\0';
    return i;
}


void copy(void)
{
    int i;
    extern char line[MAXLINE], longest[MAXLINE];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
