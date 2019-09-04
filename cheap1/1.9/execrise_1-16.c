/**************************************************
* File Name: execrise_1-16.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/15:46:38
**************************************************/

#include <stdio.h>
#define MAXLINE 10

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0){

        printf("len %d, line: %s", len, line);
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("len %d, longest:%s\n", max, longest);

    return 0;
}


int _getline(char s[], int lim)
{
    int c, i, j;
    for(i=0, j=0; (c = getchar())!=EOF && c!='\n'; ++i){
        if(i < lim - 1)
            s[j++] = c;
    }
    if (c == '\n') {
        if(i <= lim - 1){
            s[j++] = c; 
        }
        ++i;
    }
    s[j] = '\0';
    return i;
}


void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
