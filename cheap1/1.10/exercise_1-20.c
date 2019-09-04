/**************************************************
* File Name: exercise_1-20.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-27/14:44:09
**************************************************/

#include <stdio.h>
#define TABEND 8
#define MAXLINE 100

char line[MAXLINE], nline[MAXLINE];
int _getline(void);
void detab(void);

/**
 * detab 将输入中的制表符替换成适当数目的空格，使空格
 * 充满到下一个制表符终止位的地方，比如每n列就会出现一个制表符终止符
 */
int main()
{
    int len;
    while ((len = _getline()) > 0) {
        detab();     
        printf("len:%d, nline:%s", len, nline); 
    }
    return 0;
}


int _getline(void)
{
    int c,i;
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


void detab(void)
{
    int i, j, pos, nspace;
    extern char line[MAXLINE], nline[MAXLINE];    
    pos = 0;
    for (i=0, j=0; line[i]!='\n'; ++i){
        if (line[i] == '\t'){
            pos = TABEND - (j % TABEND);     
            for (nspace = 0; nspace < pos; ++nspace){
                nline[j++] = '*'; 
            } 
        }else{
            nline[j++] = line[i];
        }
    }
    nline[j++]='\n';
    nline[j] = '\0';

}
