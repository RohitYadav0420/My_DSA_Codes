#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *newnode(char ch)
{
    struct node *Node = malloc(sizeof(struct node));

    Node->data = ch;
    Node->left = Node->right = NULL;

    return Node;
}

int search(char in[], int instart, int inend, char ch)
{
    int i;
    for (i = instart; i <= inend; i++)
    {
        if (in[i] == ch)
        {
            return i;
        }
    }
}

struct node *buildtree(char pre[], char in[], int instart, int inend)
{
    static int preindex = 0;

    if (instart > inend)
    {
        return NULL;
    }

    struct node *root = newnode(pre[preindex++]);

    if (instart == inend)
    {
        return root;
    }

    int inindex = search(in, instart, inend, root->data);

    root->left = buildtree(pre, in, instart, inindex - 1);
    root->right = buildtree(pre, in, inindex + 1, inend);

    return root;
}

void printinorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printinorder(root->left);
    printf("%c ", root->data);
    printinorder(root->right);
}

int main()
{
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C', '\0'};

    int l = strlen(in);

    struct node *root = buildtree(pre, in, 0, l - 1);

    printf("inorder traversal of created tree is: \n");

    printinorder(root);

    return 0;
}