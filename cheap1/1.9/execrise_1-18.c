/**************************************************
* File Name: execrise_1-18.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/20:36:55
**************************************************/

#include <stdio.h>
#define MAXLINE 100

int _getline(char line[], int maxline);
int _remove(char s[]);

/**
 * 删除每个输入行末尾的空格及制表符，并且删除完全是空格的行
 */
int main()
{
    int len;
    char line[MAXLINE]; 
    while ((len = _getline(line, MAXLINE)) > 0) {
        if(_remove(line)>0)
            printf("len:%d, line:%s", len, line);
    }
    return 0;
}


int _getline(char s[], int lim)
{
    int c, i, j;
    for (i=0, j=0; (c = getchar())!=EOF && c!='\n'; ++i){
        if (i<lim-1)
            s[j++] = c;
    }
    if (c == '\n') {
        if (i<=lim-1)
            s[j++]=c;
        ++i;
    }
    s[j] = '\0';
    return i;
}


int _remove(char s[])
{
    int i;
    i=0;
    while(s[i] !='\n')
        ++i;
    --i;

    while (i >= 0 && (s[i] == '\t' || s[i] == ' '))
        --i;
    if (i>=0){
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    
    }
    return i;
}
