/**************************************************
* File Name: exercise_2-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-03/15:05:06
**************************************************/

#include <stdio.h>
#define MAXLINE 100

int main()
{
    int c, i;
    char s[MAXLINE];    
    for (i=0; i<MAXLINE-1;++i){
        c = getchar();
        if (c=='\n')
            break;
        if (c==EOF)
            break;
        s[i] = c;
    }

    s[++i] = '\n';
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}
