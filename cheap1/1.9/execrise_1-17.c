/**************************************************
* File Name: execrise_1-17.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/17:15:14
**************************************************/

#include <stdio.h>
#define MAXLINE 100
#define LONGLINE 5
int _getline(char line[], int lim);

/**
 * 打印长度大于80个字符的所有输入行
 */
int main()
{
    int len;
    int max;

    char line[MAXLINE];    

    max = 0;
    while((len = _getline(line, MAXLINE)) > 0){
        if (len > LONGLINE){
            printf("len:%d, line:%s", len, line);
        }
    }
    return 0;
}

int _getline(char s[], int lim)
{
    int i, j, c;
    for (i=0, j=0; (c = getchar())!=EOF && c!='\n'; ++i)
        if(i<lim-1)
            s[j++] = c;
    if (c == '\n') {
        if (i <= lim - 1) 
            s[j++] = c;
        ++i;
    }       
    s[j] = '\0';
    return i;
}

