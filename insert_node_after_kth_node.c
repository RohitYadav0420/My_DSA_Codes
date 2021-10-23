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

void insert_node(struct node* p, int k){
    int i,n;
    struct node* q;
    for(i=0;i<k-1;i++)
    {
        p=p->next;

    }
    q=(struct node*)malloc(sizeof(struct node));
    printf("enter data of inserted node: ");
    scanf("%d",&n);

    q->data=n;
    q->next=p->next;
    p->next=q;


}



int main()
{
    int n,x;
    struct node *p;
    printf("enter size of linked_list: ");
    scanf("%d",&x);
    printf("enter after which node to insert the node: ");
    scanf("%d",&n);

    p=create_list(x);
    insert_node(p,n);

    printf("linked_list after inserting: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

    return 0;




}