/**************************************************
* File Name: itoa.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-27/14:52:07
**************************************************/

#include <stdio.h>
#include <string.h>
char s[100];

void itoa(int n)
{
    static int i;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10) 
        itoa(n / 10); 
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

void reverse(char s[], int i, int len)
{
    int c, j;
    j = len - (i + 1);
    if (i < j) {
        c = s[i]; 
        s[i] = s[j];
        s[j] = c;

        reverse(s, ++i, len);
    }
}

int main()
{
    itoa(123);
    printf("%s\n", s);
    char line[100] = "I Love You";
    reverse(line, 0, strlen(line));
    printf("%s\n", line);
    return 0;
}
