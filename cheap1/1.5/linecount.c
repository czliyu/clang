/**************************************************
* File Name: linecount.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:18:45
**************************************************/

#include <stdio.h>

/*
 * 行计数
 * */
int main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl; 
    } 
    printf("%d\n", nl);
    return 0;
}
