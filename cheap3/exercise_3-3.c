/**************************************************
* File Name: exercise_3-3.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-10/22:25:44
**************************************************/

#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
    char str[100]; 
    char str1[100];
    char str2[100];
    expand("a-d0-9", str);
    printf("%s\n", str);
    expand("A-Z", str1);
    printf("%s\n", str1);
    expand("a-c-f", str2);
    printf("%s\n", str2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    i = 0;
    
    for (i=0; s1[i]!='\0'; i++) {
        if (s1[i]=='-' && s1[i-1] < s1[i+1]) {
            for (int k=0; k<s1[i+1]-s1[i-1]; k++) {
                s2[j++] = s1[i-1] + k;
            }
        }else{
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

