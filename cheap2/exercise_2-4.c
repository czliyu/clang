/**************************************************
* File Name: exercise_2-4.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-04/10:30:46
**************************************************/

#include <stdio.h>
#define MAX 50

void squeeze(char s1[], char s2[])
{
    int i,j,index;
    for (index=0; s2[index]!='\0';++index)
    {
        for (i=j=0; s1[i]!='\0';++i) 
        {
            if (s1[i]!=s2[index]) 
                s1[j++] = s1[i];
        }
        s1[j] = '\0';
    }
}


int main()
{
    char s1[MAX] = "test sequeeze";
    char s2[MAX] = "test";
    squeeze(s1, s2); 
    printf("%s\n", s1);

    return 0;
}
