#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isFull(struct Node* root)
{
    if(root == NULL)
        return 1;

    if(root->left == NULL && root->right == NULL)
        return 1;

    if(root->left != NULL && root->right != NULL)
        return isFull(root->left) && isFull(root->right);

    return 0;
}

void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    root->right->left = createNode(60);
    root->right->right = createNode(70);

    printf("Preorder: ");
    preorder(root);

    printf("\n");

    if(isFull(root))
        printf("The tree is a Full Binary Tree");
    else
        printf("The tree is not a Full Binary Tree");

    return 0;
}