/**************************************************
* File Name: wordcount.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:59:01
**************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0
/**
 * 单词计数
 */
int main()
{
    int c, nl, nw, nc, state; 
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }    
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;

}
