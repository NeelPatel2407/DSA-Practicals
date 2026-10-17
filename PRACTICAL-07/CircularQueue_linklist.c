#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

int isEmpty()
{
    return front==NULL;
}

void enqueue(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;

    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
        newNode->next=newNode;
    }
    else
    {
        newNode->next=front;
        rear->next=newNode;
        rear=newNode;
    }

    printf("%d inserted\n",value);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp=front;

    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
        rear->next=front;
    }

    printf("%d deleted\n",temp->data);
    free(temp);
}

void peekFront()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front: %d\n",front->data);
}

void peekRear()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Rear: %d\n",rear->data);
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp=front;

    while(1)
    {
        printf("%d ",temp->data);

        if(temp==rear)
            break;

        temp=temp->next;
    }

    printf("\n");
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek Front");
        printf("\n4. Peek Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peekFront();
                break;

            case 4:
                peekRear();
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