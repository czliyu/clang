/**************************************************
* File Name: exercise_2-5.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-04/11:29:58
**************************************************/

#include <stdio.h>
#define MAX 50

int any(char s1[], char s2[])
{
    int i,j,index;
    int result = -1;
    for (index=0; s1[index]!='\0';++index)
    {
        for (i=j=0; s2[i]!='\0';++i)
        {
            if (s1[index] == s2[i]) 
            {
                result = index;
                break;
            }
        }
    }
    return result;
}

int main()
{
    char s1[MAX] = "test any"; 
    char s2[MAX] = "a";
    int result;
    result = any(s1, s2);
    printf("%d\n", result);
    return 0;
}
