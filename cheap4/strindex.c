/**************************************************
* File Name: strindex.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-18/21:27:16
**************************************************/

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* 待查找的模式 */

int main()
{
    char line[MAXLINE];
    int found = 0;
    while (_getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line); 
            found++;
        }
    }
    return found;
}

/*
 * 将行保存到s中，并返回该行的长
 **/
int _getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;

}
