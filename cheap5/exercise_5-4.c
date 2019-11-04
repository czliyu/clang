/**************************************************
* File Name: exercise_5-4.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-25/10:57:34
**************************************************/

#include <stdio.h>

int strend(char *s, char *t)
{
    while (*s != *t) 
    {
        if (*s == '\0') 
            return 0;
        s++;
    }

    while (*s == *t)
    {
        if (*s == '\0') 
            return 1;
        s++;
        t++;
    }
    return 0;
}

int main()
{
    char s[] = "hello world!";     
    char t[] = "world!";
    printf("%d", strend(s, t));
    return 0;
}
