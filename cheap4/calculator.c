/**************************************************
* File Name: calculator.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-23/20:29:41
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 /* 操作数或运算符最大长度 */
#define NUMBER '0'
#define MAXVAL 100 /* 栈最大深度 */
#define BUFSIZE 100


int gettop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0; /* 下一个空间栈位置*/

double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0; /* buf中下一个空闲位置*/

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
/**
 * 把f压入栈中
 *
 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stock full, can't push %g\n", f);
}

/* 弹出 并返回栈顶的值 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty"); 
        return 0.0;
    }
}

/* 获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;
    while ((s[0]=c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) 
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
        
}

/**
 * 逆波计算器
 */
int main()
{
    int type;
    double op2;
    char s[MAXOP]; 

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s)); 
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }
    return 0;
}
