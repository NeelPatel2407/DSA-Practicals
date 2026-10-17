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

void insertleft(struct Node* parent, int value)
{
    parent->left = createNode(value);
}

void insertright(struct Node* parent, int value)
{
    parent->right = createNode(value);
}

void preorderTraversal(struct Node* node)
{
    if(node == NULL)
        return;

    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(struct Node* node)
{
    if(node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

int findDepth(struct Node* root)
{
    int depth = 0;

    while(root != NULL)
    {
        depth++;
        root = root->left;
    }

    return depth;
}

int isPerfectBinaryTree(struct Node* root, int depth, int level)
{
    if(root == NULL)
        return 1;

    if(root->left == NULL && root->right == NULL)
        return (depth == level + 1);

    if(root->left == NULL || root->right == NULL)
        return 0;

    return isPerfectBinaryTree(root->left, depth, level + 1) &&
           isPerfectBinaryTree(root->right, depth, level + 1);
}

int main()
{
    struct Node* root = createNode(10);

    insertleft(root, 20);
    insertright(root, 30);

    insertleft(root->left, 40);
    insertright(root->left, 50);

    insertleft(root->right, 60);
    insertright(root->right, 70);

    printf("Binary Tree - Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Binary Tree - Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    int depth = findDepth(root);

    if(isPerfectBinaryTree(root, depth, 0))
        printf("The tree is a Perfect Binary Tree\n");
    else
        printf("The tree is not a Perfect Binary Tree\n");

    return 0;
}