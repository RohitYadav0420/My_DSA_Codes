#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_circular_list(int n){
    
    int i,value;
    struct node *head, *p, *q;
    head=(struct node*)malloc(sizeof(struct node));
    for(i=0;i<n;i++)
    {
        printf("enter data of linked_list: ");
        scanf("%d",&value);

        if(i==0)
        {
            head->data=value;
            head->next=NULL;
            p=head;

        }
        else
        {
            q=(struct node*)malloc(sizeof(struct node));
            q->data=value;
            q->next=head;
            p->next=q;
            p=q;
        }
    }

    return head;
}

void insert_node_circular(struct node* p, int k){
    int i;
    struct node* q;
    for(i=0;i<k-1;i++)
    {
        p=p->next;

    }

    q=(struct node*)malloc(sizeof(struct node));
    printf("enter data of inserting node: ");
    scanf("%d",&q->data);
    q->next = p->next;
    p->next=q;

}

int main()
{
    int n, x;
    struct node* p;
    struct node* head;
    printf("enter no.of elements in linked list: ");
    scanf("%d",&n);
    printf("enter node after which to insert: ");
    scanf("%d",&x);
    p=create_circular_list(n);
    head=p;
    insert_node_circular(p,x);
    printf("linked list after inserting node: ");
    do 
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);

    return 0;

}
