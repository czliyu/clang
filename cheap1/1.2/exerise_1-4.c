/**************************************************
* File Name: exerise_1-4.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:26:36
**************************************************/

#include <stdio.h>

/**
 * 摄氏温度转换为华氏温度
 */
int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8;
    upper = 100;
    step = 15;

    celsius = lower;
    while(celsius <= upper){
        fahr = celsius / (5.0/9.0) + 32.0;
        printf("%3.1f\t %6.1f\n", celsius, fahr);
        celsius = celsius+step;
    } 
    return 0;
}
