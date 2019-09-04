/**************************************************
* File Name: exercise_1-15.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/15:17:02
**************************************************/

#include <stdio.h>

double fahrToCelsius(double fahr);
int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper =300;
    step = 20;
    
    fahr = lower;
    while(fahr <= upper){
        celsius = fahrToCelsius(fahr);
        fahr = fahr+step;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    } 
    
    return 0;
}

double fahrToCelsius(double fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0); 
}
