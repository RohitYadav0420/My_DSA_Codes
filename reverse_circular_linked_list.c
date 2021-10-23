#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_circular_linkedlist(int n)
{
    int i;
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    struct node *p = head;

    printf("enter values of nodes: \n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            scanf("%d", &p->data);
        }
        else
        {
            struct node *q = malloc(sizeof(struct node));
            scanf("%d", &q->data);
            p->next = q;
            q->next = NULL;
            p = q;
        }
    }
    p->next = head;

    return head;
}

struct node *reverse_circular_list(struct node *head)
{

    struct node *previous, *current, *forward;
    struct node *q;

    current = head;
    previous = head;
    while (previous->next != head)
    {
        previous = previous->next;
    }

    do
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    } while (current != head);

    q = previous;

    return q;
}

int main()
{
    int n;
    struct node *head;
    struct node *head_rev;
    struct node *p;

    printf("enter no.of elements in circular linkedlist: ");
    scanf("%d", &n);

    head = create_circular_linkedlist(n);

    head_rev = reverse_circular_list(head);

    p = head_rev;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head_rev);

    return 0;
}