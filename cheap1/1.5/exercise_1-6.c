/**************************************************
* File Name: exercise_1-6.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:01:54
**************************************************/

#include <stdio.h>

int main()
{
    int c;
    /* ctrl-d 可看到EOF的值*/
    while ((c = getchar()) != EOF)
        putchar(c);
    printf("%d\n",c);
    return 0;
}
