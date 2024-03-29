/**************************************************
* File Name: fahr.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/09:43:29
**************************************************/

#include <stdio.h>

/*
 * 当fahr=0,20,...300时
 * 分别打印华氏温度与摄氏温度对照表
 * */
int main()
{
    int fahr, celsius; 
    int lower, upper, step;
    
    lower = 0;  /* 温度表的下限 */
    upper = 300; /* 温度表的上限*/
    step = 20; /* 步长*/
    
    fahr = lower;
    while (fahr <= upper){
        celsius = 5 * (fahr-32)/9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    } 
    return 0;
}
