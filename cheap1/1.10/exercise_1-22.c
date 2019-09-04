/**************************************************
* File Name: exercise_1-22.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-28/15:14:30
**************************************************/

#include <stdio.h>
#define TURNLEN 8
#define MAXLINE 100
#define IS_SPACE 1
char line[MAXLINE], nline[MAXLINE];
int _getline(void);
void turn(void);

/**
 * 将较长的输入行折行打印
 */
int main()
{
    int len;
    extern char line[MAXLINE]; 

    while ((len = _getline()) > 0){  
        turn();    
        printf("%s", nline);
    }
    return 0;

}


int _getline(void)
{
    int c, i;
    extern char line[MAXLINE];

    for (i=0; i<MAXLINE-1 && (c = getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i; 
    }
    line[i] = '\0';
    return i;
}


void turn(void)
{
    int i,j,pos;
    extern char line[MAXLINE], nline[MAXLINE];

    pos = 0;
    for (i=0, j=0; line[i]!='\n'; ++i) {
        nline[j++] = line[i];
        if ((j % TURNLEN) == 0){ 
            while(nline[j-1] != ' ') {
                --j;
            }
            nline[j++] = '\n';
        }
    }
        
    nline[j++] = '\n';
    nline[j] = '\0';
}
