/**************************************************
* File Name: charcount.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:11:18
**************************************************/

#include <stdio.h>

/**
 * 字符统计
 */
int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    return 0;
}
