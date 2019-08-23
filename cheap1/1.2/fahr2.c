/**************************************************
* File Name: 1.2/fahr2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:07:09
**************************************************/

#include <stdio.h>

/*
 * 将温度精确到小数
 * */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    } 
    return 0;
}
