/**************************************************
* File Name: exercise_2-1-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-03/09:50:17
**************************************************/

#include <stdio.h>

int main()
{
    printf("采用计算的方式\n");    
    printf("signed char min = %d\n", -(char)((unsigned char)~0>>1)-1);
    printf("signed char max = %d\n", (char)((unsigned char)~0>>1));
    printf("signed short min = %d\n", -(short)((unsigned short)~0>>1)-1);
    printf("signed short max = %d\n", (short)((unsigned short)~0>>1));
    printf("signed int min = %d\n", -(int)((unsigned int)~0>>1)-1);
    printf("signed int max = %d\n", (int)((unsigned int)~0>>1));
    printf("signed long min = %ld\n", -(long)((unsigned long)~0>>1)-1);
    printf("signed long max = %ld\n", (long)((unsigned long)~0>>1));

    printf("unsigned char max = %u\n", (unsigned char)~0);
    printf("unsigned short max = %u\n", (unsigned short)~0);
    printf("unsigned int max = %u\n", (unsigned int)~0);
    printf("unsigned long max = %lu\n", (unsigned long)~0);
    return 0;
}
