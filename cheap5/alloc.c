/**************************************************
* File Name: alloc.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-09/09:23:22
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n; 
        return allocp - n;
    } else 
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int main()
{
    return 0;
}
