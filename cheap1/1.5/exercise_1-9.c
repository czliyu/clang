/**************************************************
* File Name: exercise_1-9.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:28:44
**************************************************/

#include <stdio.h>

/**
 * 将输入复制到输出，并将多个空格变成一个
 * 下面章节有更好的方法，这里还是用数字统计来做吧
 */
int main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if(c == ' '){
            ++nl;
            continue;
        } else if (nl > 1){ 
            putchar(' ');
            nl = 0;
        }
        putchar(c);
    }
    return 0;
}
