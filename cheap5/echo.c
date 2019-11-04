/**************************************************
* File Name: echo.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-30/10:13:40
**************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) 
        printf("%s%s\n", argv[i], (i < argc-1) ? " " : "");
    return 0;
}
