/**************************************************
* File Name: expr.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-30/11:50:06
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char c;
    static char *p;
    while (--argc > 0) {
        c = *++argv; 
        switch (c) {
            case '+':
                break;
            default:
                *p++ = c;
                printf("%s\n", p);
                continue;
        }
    }
    return 0;
}
