/**************************************************
* File Name: exercise_3-5.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-11/22:23:26
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i]; 
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b)
{
    int i, sign, num;
    i = 0;
    sign = n;
    do{
        if (sign < 0)
            num = -(sign % b);
        else
            num = sign % b;

        if (num < 10)
            s[i++] = num + '0';
        else
            s[i++] = num - 10 + 'a';
    }while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main()
{
    char s [100]; 
    itob(19, s, 16);
    printf("%s\n", s);
    return 0;
}
