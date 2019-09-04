/**************************************************
* File Name: exercise_1-13.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/14:51:27
**************************************************/

#include <stdio.h>


/**
 * 输入中单词长度的直方图
 */
int main()
{
    int c,i,vcol,j;
    int ndigit[10];
    vcol = 0;

    for (i=0; i<10;++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            putchar(':');
            for (j=0;j<ndigit[vcol];++j)
                printf("#");
            printf("\n");
            ++vcol;
        }else{
            ++ndigit[vcol];
            putchar(c);
        } 
    }
    return 0;
}
