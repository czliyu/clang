/**************************************************
* File Name: exercise_1-12.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/13:56:36
**************************************************/

#include <stdio.h>
#define OUT 1
#define IN 0

/**
 * 每行一个单词的形式打印其输入
 */
int main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            putchar('\n');
        } else {
            putchar(c);
        }
    }
    return 0;
}
