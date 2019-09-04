/**************************************************
* File Name: exercise_2-6.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-04/14:58:39
**************************************************/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0<<n);
}
/**
 * 将x中从第p位开始的n个位设置为y中最右边n位的值，x的其余各位保持不变
 */
int main()
{
    unsigned int result;
    result = getbits(255, 4, 3); 
    printf("%u", result);
    return 0;
}
