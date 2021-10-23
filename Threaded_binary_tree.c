#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    bool rthread;
};

struct node *maketree(int data)
{
    struct node *root = malloc(sizeof(struct node));

    root->data = data;

    root->left = root->right = NULL;

    return root;
}

void setleft(struct node *p, int data)
{
    if (p == NULL)
    {
        return;
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    temp->left = NULL;
    p->left = temp;

    temp->right = p;
    temp->rthread = true;
}

void setright(struct node *p, int data)
{
    if (p == NULL)
        return;

    struct node *temp = malloc(sizeof(struct node));

    temp->data = data;

    temp->left = NULL;

    p->rthread = false;
    temp->right = p->right;

    p->right = temp;

    temp->rthread = true;
}

void inorder_traversal_threaded_binary_tree(struct node *root)
{
    if (root == NULL)
        return;

    struct node *temp = root;

    while (temp != NULL)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        printf("%d ", temp->data);

        if (temp->rthread  && temp->right!=NULL)
        {
            temp = temp->right;
            printf("%d ", temp->data);
        }

        temp = temp->right;
    }
    

    
}


void preorder_traversal_iterative_threaded_binarytree(struct node* root)
{
    if(root==NULL)
    {
        return;
    }

    struct node* temp=root;

    while(temp!=NULL)
    {
        while(temp->left!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->left;

        }

        printf("%d ",temp->data);
        if(temp->rthread)
        {
            temp=temp->right;
        }

        temp=temp->right;
    }
}

int main()
{
    struct node *root = maketree(1);

    setleft(root, 2);
    setright(root, 3);
    setleft(root->left, 4);
    setright(root->left, 5);

   
    printf("inorder traversal iterative method using threaded binary tree: ");

    inorder_traversal_threaded_binary_tree(root);

    printf("\n\npreorder traversal iterative method using threaded binary tree: ");

    preorder_traversal_iterative_threaded_binarytree(root);

    return 0;
}
