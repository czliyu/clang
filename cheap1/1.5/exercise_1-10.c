/**************************************************
* File Name: exercise_1-10.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:48:03
**************************************************/

#include <stdio.h>

/*
 * 将制表符替换为\t，将回退符替换\b，将反斜杠替换为\\
 * */
int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            printf("\\t");
        }
        if (c == '\b'){
            printf("\\b"); /* /b的表示不知道这么写 就这样吧*/
        }
        if (c == '\\'){
            printf("\\\\"); 
        }
        putchar(c);
    }
    return 0;
}
