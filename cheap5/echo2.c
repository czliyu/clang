/**************************************************
* File Name: echo2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-30/10:19:00
**************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    while (--argc > 0) 
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}
