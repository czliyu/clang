/**************************************************
* File Name: keytab.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-11-06/16:06:59
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100



struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0
};

int getword(char *, int);

int binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof(struct key))

int main()
{
    int n;
    char word[MAXWORD];    

    printf("%lu\n", NKEYS);
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) 
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) 
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);

    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w); 
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];

int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

