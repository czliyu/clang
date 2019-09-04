/**************************************************
* File Name: exercise_1-4-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-26/14:30:41
**************************************************/

#include <stdio.h>

int main()
{
    int c, i, j;
    int number = 0;
    int num[26];
    char string[26];

    for (i=0; i<26; ++i)
        num[i] = 0;
    
    while ((c = getchar()) != EOF){
        if (c >= 'a' && c<='z'){
            if(++num[c-'a'] > number)
               number = num[c-'a']; 
        }
    }
    
    for (i=number; i>0; --i){
        for (j=0;j<26;++j){
            if(num[j] >= i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=0;i<26;++i){
        printf("%c", 'a'+i);
    }
    return 0;
}
