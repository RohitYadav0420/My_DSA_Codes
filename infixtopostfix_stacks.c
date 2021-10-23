#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int max;
    char *s;
};

struct stack *stk;

void push(char value, int n)
{
    if (stk->top == n - 1)
        return;

    stk->s[++stk->top] = value;
}

int isempty()
{
    return stk->top == -1;
}

char pop()
{
    if (isempty())
        exit(1);

    return stk->s[stk->top--];
}

int operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    else
        return 0;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *infixtopostfix(char *infix, int n)
{
    stk = (struct stack *)malloc(sizeof(struct stack));
    int i = 0, j = 0;

    stk->top = -1;
    stk->max = n;

    stk->s = (char *)malloc(sizeof(char) * (strlen(infix) + 1));

    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));

    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stk->s[stk->top]))
            {
                push(infix[i], n);
                i++;
            }
            else
            {

                postfix[j] = pop();
                j++;
            }
        }
    }

    while (!isempty())
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char s[100];
    int n;

    printf("enter the infix expression: ");
    scanf("%s", s);

    n = strlen(s);

    printf("postfix expression is: \n");

    printf("%s", infixtopostfix(s, n));

    return 0;
}