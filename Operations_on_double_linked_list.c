#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *create_double_linked_list(int n)
{
    struct node *head = malloc(sizeof(struct node));
    struct node *p, *q;
    int i;

    printf("enter elements of double linkedlist\n");

    head->prev = NULL;
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
            q->prev = p;
            p->next = q;
            q->next = NULL;
            p = q;
        }
    }

    return head;
}

void display_double_linkedlist(struct node *head)
{
    struct node *p;

    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

void no_of_nodes_in_double_linked_list(struct node *head)
{
    int count = 0;
    struct node *p;
    p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    printf("\nno.of elements in double linked list are: %d\n", count);
}

void insert_node_after_kth_node_in_double_linked_List(struct node *head, int k, int n)
{
    struct node *p = head;
    struct node *q;
    struct node *r;
    int i;

    for (i = 0; i < k - 1; i++)
    {
        p = p->next;
    }

    q = malloc(sizeof(struct node));

    q->data = n;
    q->prev = p;
    r = p->next;
    q->next = r;
    p->next = q;
    r->prev = q;
}

void delete_node_after_kth_node(struct node *head, int k)
{
    struct node *p = head;
    struct node *q;
    struct node *r;
    int i;
    for (i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    q = p->next;
    r = q->next;
    p->next = r;
    r->prev = p;

    free(q);
}

int main()
{
    int n, x, y;
    int a;
    struct node *p, *q;
    printf("enter no.of elements in double_linkedlist: ");
    scanf("%d", &n);

    p = create_double_linked_list(n);
    q = p;

    printf("double linked list is: ");
    display_double_linkedlist(p);

    no_of_nodes_in_double_linked_list(p);

    printf("enter x after which to insert node: ");
    scanf("%d", &x);

    printf("enter value to insert: ");
    scanf("%d", &a);

    insert_node_after_kth_node_in_double_linked_List(p, x, a);

    printf("list after inserting\n");
    display_double_linkedlist(p);

    printf("enter y after which to delete node: ");
    scanf("%d", &y);

    delete_node_after_kth_node(q, y);

    printf("list after deleting node\n");
    display_double_linkedlist(q);

    return 0;
}
