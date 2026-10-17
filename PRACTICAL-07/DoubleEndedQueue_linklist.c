#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void insertFront(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=front;

    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        front->prev=newNode;
        front=newNode;
    }

    printf("%d inserted at front\n",value);
}

void insertRear(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=rear;

    if(rear==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }

    printf("%d inserted at rear\n",value);
}

void deleteFront()
{
    if(front==NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp=front;

    printf("%d deleted from front\n",temp->data);

    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
        front->prev=NULL;
    }

    free(temp);
}

void deleteRear()
{
    if(rear==NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp=rear;

    printf("%d deleted from rear\n",temp->data);

    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        rear=rear->prev;
        rear->next=NULL;
    }

    free(temp);
}

void display()
{
    if(front==NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp=front;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}