/**************************************************
* File Name: qsort.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-13/10:55:12
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* 进行排序的最大文本行数 */
#define MAXLEN 1000 /* 每行输入文本行的最大长度 */
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int _getline(char *, int);
char *alloc(int);

char *lineptr[MAXLINES]; /* 指向文本行的指针指数 */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[], int left, int right, int type, int (*comp) (void *, void *));

int numcmp(char *, char *);

int strmycmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int c, numeric = 0, type = 0, f = 0, d = 0;
    int (*comp) (void *, void *) = strcmp;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'n':
                    numeric = 1;
                    comp = numcmp;
                    break;
                case 'r':
                    type = 1;
                    break;
                case 'f':
                    f = 1;
                    comp = strmycmp;
                    break;
                case 'd':
                    d = 1;
                    break;
                default:
                    printf("qsort2: illegal option %c\n", c);
                    argc = 0;
                    break;
            } 
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        _qsort((void **) lineptr, 0, nlines-1, type, comp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n"); 
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) 
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int _getline(char *line, int lim)
{
    int c;
    char *p = line;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *p++ = c; 
    }
    if (c == '\n')
        *p++ = '\0';
    return p - line;
}

void _qsort(void *v[], int left, int right, int type, int (*comp) (void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        switch(type) {
            case 1:
                if ((*comp) (v[i], v[left]) > 0) 
                    swap(v, ++last, i);
                break;
            default:
                if ((*comp) (v[i], v[left]) < 0) 
                    swap(v, ++last, i);
                break;
        }
    }
    swap(v, left, last);
    _qsort(v, left, last-1, type, comp);
    _qsort(v, last+1, right, type, comp);

}


void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void low(char *s, char *t)
{
    while (*t != '\0')
    {
        if (*t >= 'A' && *t <= 'Z') 
            *s++ = *t + ('a' - 'A');
        else
            *s++ = *t;
        t++;
    }
    *s++ = '\0';
}

int strmycmp(char *s1, char *s2)
{
    char t1[100], t2[100];
    low(t1, s1);
    low(t2, s2);
    return strcmp(t1, t2);
}


char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; 
    } else
        return 0;
}

