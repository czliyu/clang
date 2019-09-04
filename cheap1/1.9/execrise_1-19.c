/**************************************************
* File Name: execrise_1-19.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/22:03:13
**************************************************/

#include <stdio.h>
#define MAXLINE 100

int _getline(char line[], int maxline);
void reverse(char s[]);

/**
 * 将字符串倒序排列
 */
int main()
{
    int len;
    char line[MAXLINE]; 
    while ((len = _getline(line, MAXLINE)) > 0){
    
        reverse(line);
        printf("len:%d, line:%s\n", len, line);
    }
    return 0;
}


int _getline(char s[], int lim)
{

    int c, i;
    for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
        s[i]=c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }    
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
    int i, j, l;
    char temp;
    i = j = 0;
    while(s[i] != '\n')
        ++i;
    for (j=0, l = i-1; j<(i-1)/2; j++, l--){
        temp = s[j];
        s[j] = s[l];
        s[l] = temp;    
    }
    s[i] = '\0';
}
