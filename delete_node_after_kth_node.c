#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_list(int n){
    int i;
    struct node *head, *p, *q;
    head= (struct node*) malloc(sizeof(struct node));
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head->data=i;
            head->next=NULL;
            p=head;
        }
        else{
        q=(struct node*)malloc(sizeof(struct node));
        q->data=i;
        q->next=NULL;
        p->next=q;
        p=q;
        }

    }
    return head;
}

void delete_node(struct node* p, int k)
{
    int i;
    struct node* q;
    for(i=0;i<k-1;i++)
    {
        p=p->next;
    }

    q=p->next;
    p->next=q->next;
    free(q);

}

int main()
{

    int n,x;
    struct node *p;
    printf("enter no.of elements in linked list: ");
    scanf("%d",&n);
    printf("enter after which node to delete the node: ");
    scanf("%d",&x);

    p= create_list(n);

    delete_node(p,x);
    printf("linked list after deleting node is: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

    return 0;

}