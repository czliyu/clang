/**************************************************
* File Name: exercise_3-4.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-11/21:21:04
**************************************************/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;
    for (i=0, j=strlen(s)-1;i<j;i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}

void itoa2(int n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        if (sign < 0) 
            s[i++] = -(n % 10) + '0';
        else
            s[i++] = n % 10 + '0';
    }while((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    }while ((n/=10) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0'; 
    reverse(s);
}
int main()
{
    char s[1024];
    itoa(10, s); 
    printf("%s\n", s);
    itoa2(-128,s);
    printf("%s\n", s);
    return 0;
}
