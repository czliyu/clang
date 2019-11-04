/**************************************************
* File Name: grep.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-30/10:45:20
**************************************************/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int _getline(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE]; 
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    // -nx 模式
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch(c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            } 
        } 
    }
    
    if (argc != 1)
        printf("uage: find -x -n pattern\n");
    else {
        while (_getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line); 
                found++;
            }
        }
    }
    return found;
}

int _getline(char *line, int slim)
{
    int c, i;
    char *p = line;
    while (--slim > 0 && (c = getchar()) != EOF && c != '\n')
        *p++ = c;
    return p - line;
}
