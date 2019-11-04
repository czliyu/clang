/**************************************************
* File Name: stack.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-26/09:07:45
**************************************************/

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty");
        return 0.0;
    }
}
