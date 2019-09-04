/**************************************************
* File Name: exercise_1-14.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-25/07:40:39
**************************************************/

#include <stdio.h>

/***
 *
 * 打印输入中各个符号的出现频率直方图
 */
int main()
{
    int c, i, j;
    int num[26], blacknumber = 0, othersnumber = 0;
    char string[26];

    for (i=0; i<26; ++i)
        num[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= 'a' && c <= 'z')
            ++num[c-'a']; 

    for(i=0;i<26; ++i){
        printf("   %c:", 'a'+i);
        for (j=0; j<num[i]; ++j)
            printf("*");
        printf("\n");
    }
    return 0;
}
