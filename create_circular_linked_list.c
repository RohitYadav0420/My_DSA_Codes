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


void display_circular_list(struct node* p){
    struct node* head;
    head=p;
    
    if(p==NULL)
    printf("circular linked list is empty\n");
    else
    {
        do
        {
            printf("%d ",p->data);
            p=p->next;
        }while(p!=head);

    }
    printf("\n");
    
}

void count_circular_list(struct node* p){
    
    struct node* head;
    head=p;
    int count=0;
    if(p==NULL)
    printf("circular linked list is empty\n");
    else{
    do
    {
        count++;
        p=p->next;
    } while (p!=head);

    }
    printf("%d",count);
    
}

int main()
{
    int n;
    struct node* p;
    printf("enter size of circular linked list: ");
    scanf("%d",&n);
    p=create_circular_list(n);
    printf("circular linked list is: ");
    display_circular_list(p);
    printf("no.of elements in linked list are: ");
    count_circular_list(p);

    return 0;
    
}

