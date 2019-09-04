/**************************************************
* File Name: copy.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:57:18
**************************************************/

#include <stdio.h>

int main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar(); 
    } 
    return 0;
}
