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

int skip_members_of_node(struct node *head, int n)
{

    int i;
    struct node *p;
    struct node *q;

    int count = 0;
    p = head;

    if (p == NULL)
        count = 0;
    else
    {
        do
        {

            count++;
            p = p->next;

        } while (p != head);
    }

    p = head;

    if (p == NULL)
    {
        printf("list is empty\n");
        exit;
    }
    else
    {
        while (count > 1)
        {

            for (i = 0; i < n - 2; i++)
            {
                p = p->next;
            }

            q = p->next;
            p->next = q->next;
            free(q);
            p = p->next;

            count--;
        }

        return p->data;
    }
}

int main()
{

    int n, k;
    int x;
    struct node *head;
    printf("enter no of elements in circular_linkedlist: ");
    scanf("%d", &n);

    head = create_circular_linkedlist(n);

    printf("enter the number count to remove member: ");
    scanf("%d", &k);

    x = skip_members_of_node(head, k);

    printf("\nthe leader of class is number: %d", x);

    return 0;
}