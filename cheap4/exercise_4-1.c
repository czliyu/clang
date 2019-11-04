/**************************************************
* File Name: exercise_4-1.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-18/21:47:12
**************************************************/

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int max);
int strindex(char source[], char serchfor[]);

char pattern[] = "ould";

int main()
{

    char line[MAXLINE];
    int found = 0;
    while (_getline(line, MAXLINE) > 0) {
        printf("%d", strindex(line, pattern));
    }
    return 0;
}

int _getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar())!=EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k, o;
    o = -1;
    for (i=0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
            ;
        if (k > 0 && t[k] == '\0')
            o = i;
    }
    return o;

}
