#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_linear_linked_list(int n)
{
    int i;
    struct node *head, *p, *q;

    head = malloc(sizeof(struct node));

    head->next = NULL;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            scanf("%d", &head->data);
            p = head;
        }
        else
        {
            q = malloc(sizeof(struct node));
            scanf("%d", &q->data);
            p->next = q;
            q->next = NULL;
            p = q;
        }
    }

    return head;
}

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

void check_for_loop(struct node *head)
{
    struct node *f, *s;
    f = head;
    s = head;
    while (f != NULL && f->next != NULL)
    {
        f = f->next->next;
        s = s->next;
        if (f == s)
        {
            printf("linked_list has loop\n");
            exit(0);
        }
    }

    printf("Linked_list doesn't has loop\n");
}

int main()
{
    int n, x;
    struct node *p;
    printf("enter no.of elements in linked list: ");
    scanf("%d", &n);

    p = create_linear_linked_list(n);
    printf("\nchecking for loop while passing in linearlinked list\n\n");
    check_for_loop(p);
    printf("enter no.of elements in linked list: ");
    scanf("%d", &x);
    p = create_circular_linkedlist(x);

    printf("\nchecking for loop whhile passing in circular linked list\n\n");

    check_for_loop(p);

    return 0;
}