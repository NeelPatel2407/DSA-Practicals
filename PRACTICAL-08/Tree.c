#include<stdio.h>
#include<stdlib.h>

#define MAX_CHILDREN 10

struct Node{
    int data;
    struct Node *children[MAX_CHILDREN];
    int childcount;
};

struct Node* creatNode(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->childcount=0;

    for(int i=0; i<MAX_CHILDREN; i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

void insertchild(struct Node *parent, struct Node *child){
    if(parent->childcount < MAX_CHILDREN){
        parent->children[parent->childcount]=child;
        parent->childcount++;

        printf("%d inserted as a child of %d\n", child->data, parent->data);
    }
    else{
        printf("Cannot inserted more children under %d\n", parent->data);
    }
}

void displayTree(struct Node *root, int level){
    if(root==NULL){
        return;
    }
    for(int i=0; i<level; i++){
        printf(" ");
    }
    pritnff("%d\n");

    for(int i=0; i<root->childcount; i++){
        displayTree(root->children[i], level+1);
    }
}

int main(){
    struct Node *root=creatNode(10);
    struct Node *node2=creatNode(20);
    struct Node *node3=creatNode(30);
    struct Node *node4=creatNode(40);
    struct Node *node5=creatNode(50);

    insertchild(root, node2);
    insertchild(root, node3);
    insertchild(root, node4);
    insertchild(root, node5);

    displayTree(root, 0);
}