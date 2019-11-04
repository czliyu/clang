/**************************************************
* File Name: exercise_5-5.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-25/14:34:02
**************************************************/

#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
    char *a = s;
    char *b = t;
    for (s = a, t = b; t < b+n; t++,s++)
        *s = *t;
}

int main()
{
    char *s = "panghu "; 
    char *t = "test";
    strncpy(s, t, 2);
    printf("%s\n", s);
    return 0;
}
