/**************************************************
* File Name: exercise_5-3.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-09/11:52:48
**************************************************/

#include <stdio.h>

char *strcat(char *s, const char *t)
{
    char *p = s;

    while (*s++)
        ;
    s--;
    while ((*s++ = *t++) != '\0')
        ;
    return p;
        
}

int main()
{
    char s1[100] = "this is"; 
    const char *t1 = " string";
    printf("%s", strcat(s1, t1));
    return 0;
}
