/**************************************************
* File Name: exercise_4-11.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-03/19:39:20
**************************************************/

#include <stdio.h>
#include <string.h>

#define swap(t, x, y) { int temp; temp = t[x]; t[x] = t[y]; t[y] = temp; }

int main()
{
    char v[] = "test";
    swap(v, 1, 2);
    printf("%s", v);
    return 0;
}
