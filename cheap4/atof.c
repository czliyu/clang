/**************************************************
* File Name: atof.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-21/21:19:43
**************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* atof: 把字符串转换为相应的双精度浮点数 */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++) /* 跳过空白格 */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10.0;
    }
    return sign * val / power;
}

int _getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main()
{
    double sum, atof(char []);    
    char line[MAXLINE];
    int _getline(char line[], int max);

    sum = 0;
    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
