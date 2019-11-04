/**************************************************
* File Name: exercise_3-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-09/21:45:44
**************************************************/

#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
    char s[] = "";
    char t[] = "test\t panghu";
    escape(s, t);
    printf("%s", s);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (t[j]!='\0') {
        switch (t[j]) {
            case '\t':
                s[i] = '\\';
                s[++i] = 't';
                break;
            case '\n':
                s[i] = '\\';                
                s[++i] = 'n';
                break;
            default:
                s[i] = t[j];   
                break;
        }
        ++i;
        ++j;
    }
    s[++i] = '\0';
    s[i] = '\n';
}
