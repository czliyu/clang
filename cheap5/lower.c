/**************************************************
* File Name: lower.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-11-04/14:56:46
**************************************************/

#include <stdio.h>
#include <string.h>

char lower(char *s, char *t);

int strmycmp(char *s1, char *s2);

int main()
{
    char *s1 = "TEst";
    char *s2 = "Desc";
    printf("%d\n", strmycmp(s1, s2));
    return 0;
}

int strmycmp(char *s1, char *s2)
{
    char t1[100], t2[100];
    lower(t1, s1);
    lower(t2, s2);
    return strcmp(t1, t2);
}


char lower(char *s, char *t)
{
    while (*t != '\0') 
    {
        if (*t >= 'A' && *t <= 'Z')
            *s++ = *t + ('a' - 'A'); 
        else
            *s++ = *t;
        t++;
    }
    *s++ = '\0';
    return *s;
}
