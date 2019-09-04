/**************************************************
* File Name: for.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/10:45:20
**************************************************/

#include <stdio.h>

int main()
{
    int fahr;
    for (fahr=0; fahr<=300; fahr=fahr+20)
        printf("%3d\t %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));    
    return 0;
}
