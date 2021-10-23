#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create_linkedlist(int k)
{
    int i;
    int data;
    struct node *head;
    struct node *p;
    printf("enter data of nodes\n");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &data);
        if (i == 0)
        {
            head = malloc(sizeof(struct node));
            head->data = data;
            head->next = NULL;
            p = head;
        }
        else
        {
            struct node *q = malloc(sizeof(struct node));
            q->data = data;
            q->next = NULL;
            p->next = q;
            p = q;
        }
    }

    return head;
}

struct node *reverse_linkedlist_recursive(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node *p = head;

    struct node *q = reverse_linkedlist_recursive(p->next);

    p->next->next = p;

    p->next = NULL;

    return q;
}

void display(struct node *head)
{
    struct node *p = head;
    if (head == NULL)
        return;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *p;
    int k;
    printf("enter no.of node in linked list: ");
    scanf("%d", &k);

    head = create_linkedlist(k);

    p = reverse_linkedlist_recursive(head);

    printf("displaying reversed linked list\n");

    display(p);

    return 0;
}