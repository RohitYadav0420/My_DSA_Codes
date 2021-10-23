#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front, rear;
    int no_of_elements;
    int *arr;
    int capacity;
};

struct queue *create_queue(int size)
{

    struct queue *que = malloc(sizeof(struct queue));

    que->front = -1;
    que->rear = -1;
    que->no_of_elements = 0;

    que->arr = (int *)malloc(sizeof(int) * size);
    que->capacity = size;

    return que;
}

int isempty(struct queue *que)
{
    return que->no_of_elements == 0;
}

int full(struct queue *que)
{
    return que->no_of_elements == que->capacity;
}

int front(struct queue *que)
{
    if (isempty(que))
    {
        exit(1);
    }

    return que->arr[que->front + 1];
}

int rear(struct queue *que)
{
    if (isempty(que))
    {
        exit(1);
    }

    return que->arr[que->rear];
}

void enqueue(struct queue *que, int value)
{
    if (full(que))
    {
        printf("queue is full\n");
        return;
    }

    que->rear = (que->rear + 1) % (que->capacity);

    que->arr[que->rear] = value;

    que->no_of_elements++;
}

int dequeue(struct queue *que)
{
    if (isempty(que))
    {
        printf("queue is empty\n");
        exit(1);
    }

    que->front = (que->front + 1) % (que->capacity);

    que->no_of_elements--;

    return que->arr[que->front];
}

int main()
{
    int n;
    int f, r;
    printf("enter the size of queue: ");
    scanf("%d", &n);

    struct queue *que = create_queue(n);

    enqueue(que, 5);
    enqueue(que, 8);
    enqueue(que, 21);

    printf("\nfront and rear values till now\n");

    f = front(que);
    r = rear(que);

    printf("front= %d , rear= %d\n", f, r);

    enqueue(que, 7);
    enqueue(que, 10);

    dequeue(que);

    printf("\n\nfront and rear values till now\n");

    f = front(que);
    r = rear(que);

    printf("front= %d , rear= %d", f, r);

    return 0;
}
