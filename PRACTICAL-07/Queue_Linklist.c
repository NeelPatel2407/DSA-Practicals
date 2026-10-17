#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int value)
{
    struct Node *newNode;

    newNode=(struct Node *)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    if(front==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue()
{
    struct Node *temp;

    if(front==NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp=front;

    printf("Attended: %d\n",front->data);

    front=front->next;

    if(front==NULL){
    rear=NULL;
    }

    free(temp);
}

void display()
{
    struct Node *temp;

    if(front==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp=front;

    printf("Queue: ");

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
        printf("\n1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter patient number: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}