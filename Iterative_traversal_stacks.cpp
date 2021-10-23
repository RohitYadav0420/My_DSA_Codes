#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *maketree(int data)
{
    struct node *temp = new node();

    temp->data = data;

    temp->left = temp->right = NULL;

    return temp;
}

void setleft(struct node *p, int data)
{
    struct node *temp = maketree(data);

    p->left = temp;
}

void setright(struct node *p, int data)
{
    struct node *temp = maketree(data);

    p->right = temp;
}

void preorder_traversal_iterative(struct node *root)
{
    stack<struct node *> stk;

    if (root == NULL)
        return;

    struct node *temp = root;

    while (1)
    {
        if (temp == NULL && stk.empty())
        {
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";

            stk.push(temp);

            temp = temp->left;
        }

        temp = stk.top();
        stk.pop();

        temp = temp->right;
    }
}

void inorder_traversal_iterative(struct node *root)
{
    stack<struct node *> stk;

    if (root == NULL)
        return;

    struct node *temp = root;

    while (1)
    {
        if (temp == NULL && stk.empty())
        {
            return;
        }

        while (temp != NULL)
        {
            stk.push(temp);
            temp = temp->left;
        }

        temp = stk.top();
        stk.pop();

        cout << temp->data << " ";

        temp = temp->right;
    }
}

int main()
{
    struct node *root = maketree(1);

    setleft(root, 2);
    setright(root, 3);
    setleft(root->left, 4);
    setright(root->left, 5);

    cout << "preorder traversal is: ";

    preorder_traversal_iterative(root);

    cout << endl;

    cout << "inorder traversal is: ";

    inorder_traversal_iterative(root);

    return 0;
}