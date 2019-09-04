/**************************************************
* File Name: exercise_1-21.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-08-27/16:16:36
**************************************************/

#include <stdio.h>
#define TABLEN 8
#define MAXLINE 100

char line[MAXLINE], nline[MAXLINE];

int _getline(void);
void entab(void);

int main()
{
    int len;
    extern char nline[MAXLINE];

    while ((len = _getline())>0){
        entab();
        printf("len:%d, nline:%s", len, nline);
    }
    return 0;
}

int _getline(void)
{
    int c,i;
    extern char line[];
    for (i=0; i<MAXLINE-1 && (c = getchar())!=EOF && c!='\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void entab(void)
{
    int i,j,nb,nt;
    extern char line[MAXLINE], nline[MAXLINE];
    nb = nt = 0;
    for (i=0,j=0; line[i] != '\n'; ++i) {
        if (line[i] == ' '){
            ++nb;
            if (nb%TABLEN == 0) {
                ++nt;
                nb = 0;
            }
            continue;
        }
        while (nt) {
            nline[j++] = '\t'; 
            --nt;
        }
        while (nb){
            nline[j++] = '*';
            --nb;
        }
       
        nline[j++] = line[i];
    }
    nline[j++] = '\n';
    nline[j] = '\0';
}
