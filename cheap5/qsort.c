/**************************************************
* File Name: qsort.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-10-13/10:55:12
**************************************************/

#include <stdio.h>
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

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines; /* 读取的输入行数目 */ 

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1); 
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n"); 
        return -1;
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
    *p++ = '\0';
    return p - line;
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) 
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last + 1, right);

}


void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *alloc(int n)
{
   if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; 
    } else
        return 0;
}

