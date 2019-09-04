/**************************************************
* File Name: exercise_1-13-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/15:28:38
**************************************************/

#include <stdio.h>

/**
 * 让我来尝试一下垂直的直方图
 */
int main()
{
    int c, i, j, vcol;
    int number = 0; /*记录最大纵向的值*/ 

    int ndigit[30];
    vcol = 0;

    for (i=0; i<30; ++i) 
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t'){
            if(ndigit[vcol] > number)
                number = ndigit[vcol];
            ++vcol; 
        } else {
            ++ndigit[vcol]; /* 单词长度*/
        }

    }
    for (i=number; i>0;--i) {
        for(j=0; j<vcol; ++j) {
            if (ndigit[j] >= i)
                printf("*\t");
            else
                printf(" \t");
        }
        printf("\n");
    }

    return 0;
}
