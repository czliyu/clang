/**************************************************
* File Name: exercise_1-3.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:22:23
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("华氏温度转换表\n");
    while (fahr <= upper){
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius); 
        fahr = fahr+step;
    }    
    return 0;
}
