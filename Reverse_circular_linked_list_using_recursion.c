#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *create_circular_linkedlist(int k)
{
    int i;
    int data;
    struct node *head;
    struct node *p;
    printf("enter elements of circular linked list\n");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &data);
        if (i == 0)
        {
            head = malloc(sizeof(struct node));
            head->data = data;
            head->next = head;
            p = head;
        }
        else
        {
            struct node *q = malloc(sizeof(struct node));
            q->data = data;
            q->next = head;
            p->next = q;
            p = q;
        }
    }

    return head;
}

struct node *reverse_circular_linkedlist_recursion(struct node *head)
{
    if (head == NULL || head->next == head)
    {
        return head;
    }

    struct node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = head->next;

    struct node *q = reverse_circular_linkedlist_recursion(head->next);

    head->next->next = head;

    head->next = p;

    return q;
}

void display(struct node *head)
{
    struct node *p = head;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

int main()
{

    struct node *head = NULL;
    struct node *p;
    int k;
    printf("enter no.of node in linked list: ");
    scanf("%d", &k);

    head = create_circular_linkedlist(k);

    p = reverse_circular_linkedlist_recursion(head);

    printf("displaying reversed linked list\n");

    display(p);

    return 0;
}