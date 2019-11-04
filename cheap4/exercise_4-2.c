/**************************************************
* File Name: exercise_4-2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-23/10:09:41
**************************************************/

#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
    double val, power;
    int i, sign, expSign, expNum;
    int expRet = 1;

    for (i=0; isspace(s[i]); i++)
        i++;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10;
    }
    val = sign * val / power;

    if (s[i] == 'E' || s[i] == 'e'){
        i++;
        if (s[i] == '+' || s[i] == '-') {
            expSign = (s[i] == '+') ? 1 : -1;     
        }else{
            expSign = 1;
        }
        for (expNum = 0; isdigit(s[i]); i++) {
            expNum = 10 * expNum + (s[i] - '0'); 
        }
        for (int k=0; k<expNum; k++)
            expRet *= 10;
        if (expSign == 1)
            return val * expRet;
        else
            return val / expRet;
    }else{
        return val; 
    }
}

int main()
{
    char str[20] = "12.34";
    char str1[20] = "12.34e-6";
    double ret;
    printf("%f\n", atof(str));
    printf("%e\n", atof(str1));
    return 0;
}
