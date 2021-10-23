#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int *s;
};

struct stack *stk;

void push(int value, int n)
{
    if (stk->top == n - 1)
        return;

    stk->s[++stk->top] = value;
}

int isempty()
{
    return stk->top == -1;
}

int pop()
{
    if (isempty())
        exit(1);

    return stk->s[stk->top--];
}

int top()
{
    if (isempty())
        exit(1);

    return stk->s[stk->top];
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

int postfix_evaluation(char *postfix, int n)
{
    int i = 0;
    stk = malloc(sizeof(struct stack));

    stk->top = -1;

    stk->s = (int *)malloc(sizeof(int) * n);

    int op1;
    int op2;

    while (postfix[i] != '\0')
    {
        if (!operator(postfix[i]))
        {
            push(postfix[i] - '0', n);
            i++;
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
            {
            case '*':
                push(op1 * op2, n);
                break;

            case '/':
                push(op1 / op2, n);
                break;

            case '+':
                push(op1 + op2, n);
                break;

            case '-':
                push(op1 - op2, n);
                break;

            case '^':
                push(op1 ^ op2, n);
                break;
            }

            i++;
        }
    }

    return top();
}

int main()
{
    char s[100];

    int n, value;

    printf("enter the postfix expression\n");
    scanf("%s", s);

    n = strlen(s);

    value = postfix_evaluation(s, n);

    printf("value of evaluated postfix value is: %d", value);

    return 0;
}
