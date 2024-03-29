/**************************************************
* File Name: keytab2.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-11-06/17:09:39
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
    "break", 0,
    "case", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);

struct key *binsearch(char *, struct key *, int);

int main()
{
    char word[MAXWORD]; 
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0])) 
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    }

    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) 
            printf("%4d %s\n", p->count, p->word);
    }
    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
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
