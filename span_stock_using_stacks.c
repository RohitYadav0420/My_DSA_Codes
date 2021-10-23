#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
};

struct stack *stk;

void push(int value, int n)
{
    if (stk->top == n - 1)
        return;

    stk->arr[++stk->top] = value;
}

int empty()
{
    return stk->top == -1;
}

int pop()
{
    if (empty())
        exit(1);

    return stk->arr[stk->top--];
}

int top()
{
    if (stk->top == -1)
        exit(1);

    return stk->arr[stk->top];
}

void span_stock(int price[], int size)
{
    int s[size];
    int i = 0;

    stk = (struct stack *)malloc(sizeof(struct stack));

    stk->arr = (int *)malloc(sizeof(int) * size);

    stk->top = -1;

    s[0] = 1;

    push(i, size);

    for (i = 1; i < size; i++)
    {
        while (!empty() && price[top()] <= price[i])
            pop();

        s[i] = empty() ? (i + 1) : i - top();

        push(i, size);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", s[i]);
    }
}

int main()
{
    int price[100];
    int n, i;

    printf("enter the no.of stock prices: ");
    scanf("%d", &n);

    printf("enter price values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }

    printf("stock span values are: \n");
    span_stock(price, n);

    return 0;
}