/**************************************************
* File Name: exercise_1-8.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:21:39
**************************************************/

#include <stdio.h>

/**
 * 统计空格、制表符、换行符个数
 */
int main()
{
    int nspace, ntab, nl, c;
    nspace = ntab = nl = 0;
    while((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++ntab;
        if (c == ' ')
            ++nspace;
    } 
    printf("nspace: %d, ntab: %d, nl: %d\n", nspace, ntab, nl);
    return 0;
}
