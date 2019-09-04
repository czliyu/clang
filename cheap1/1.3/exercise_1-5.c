/**************************************************
* File Name: exercise_1-5.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:52:28
**************************************************/

#include <stdio.h>

/*
 * 倒序打印温度转换表
 * */
int main()
{
    float fahr;
    for(fahr=300; fahr>=0; fahr=fahr-20)
       printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32.0)); 
    return 0;
}
