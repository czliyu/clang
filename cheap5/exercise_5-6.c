/**************************************************
* File Name: exercise_5-6.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-28/21:50:34
**************************************************/

#include <stdio.h>
#define MAXLINE 1000

int _getline(char *, int);

int main()
{
    int nline;
    char line[MAXLINE];
    while ((nline = _getline(line, MAXLINE)) > 0) {
        printf("%s\n", line);
    }
    return 0;
}

int _getline(char *line, int lim)
{
    int c;
    char *p = line;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *p++ = c;
    }
    return p - line;
}
