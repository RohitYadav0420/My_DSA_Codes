#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    unsigned capacity;
    int *arr;
};

struct stack* create_stack(int capacity)
{
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->top = -1;
    ptr->capacity = capacity;
    ptr->arr= (int *)malloc(sizeof(int) * capacity);
    return ptr;
}



void push(struct stack* stack, int item)
{
    if(stack->top== stack->capacity -1)
    {
        printf("stack overflow\n");
        exit(1);
    }

    stack->arr[++stack->top]= item;

    printf("%d pushed to stack\n", item);

}

int pop(struct stack* stack)
{
    if(stack->top== -1)
    {
        printf("stack underflow\n");
        exit(1);
    }

    printf("%d poped from stack\n",stack->arr[stack->top]);

    return stack->arr[stack->top--];
}

int stackpeek(struct stack* stack)
{
    if(stack->top== -1)
    {
        printf("stack is empty\n");
        exit(1);
    }

    return stack->arr[stack->top];
}




int main()
{
    int n;
    printf("enter the capacity: ");
    scanf("%d",&n);


    struct stack * stack= create_stack(n);

    push(stack, 20);
    push(stack, 45);
    push(stack, 15);
    push(stack, 9);
    pop(stack);
    pop(stack);
    push(stack, 34);

    printf("top element is %d", stackpeek(stack));

    return 0;

}