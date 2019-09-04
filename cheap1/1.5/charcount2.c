/**************************************************
* File Name: charcount2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-23/11:15:23
**************************************************/

#include <stdio.h>

int main()
{
    double nc;
    for(nc=0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);    
    return 0;
}
