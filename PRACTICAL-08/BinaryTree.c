#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertLeft(struct Node *parent, int value)
{
    parent->left = CreateNode(value);
}

void insertRight(struct Node *parent, int value)
{
    parent->right = CreateNode(value);
}

void preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    struct Node *root = CreateNode(10);

    insertLeft(root, 20);
    insertRight(root, 30);
    insertLeft(root->left, 40);
    insertRight(root->right, 50);

    printf("Binary Tree - PreOrder Traversal:\n");
    preOrder(root);
    printf("\n");

    printf("Binary Tree - InOrder Traversal:\n");
    inOrder(root);
    printf("\n");

    printf("Binary Tree - PostOrder Traversal:\n");
    postOrder(root);
    printf("\n");

    return 0;
}