#include<stdio.h>

#define MAX 5

int deque[MAX];
int front=-1;
int rear=-1;

int isFull()
{
    return (front==0&&rear==MAX-1)||(front==rear+1);
}

int isEmpty()
{
    return front==-1;
}

void insertFront(int value)
{
    if(isFull())
    {
        printf("Deque is Full\n");
        return;
    }

    if(isEmpty())
    {
        front=0;
        rear=0;
    }
    else if(front==0)
    {
        front=MAX-1;
    }
    else
    {
        front--;
    }

    deque[front]=value;
}

void insertRear(int value)
{
    if(isFull())
    {
        printf("Deque is Full\n");
        return;
    }

    if(isEmpty())
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }

    deque[rear]=value;
}

void deleteFront()
{
    if(isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n",deque[front]);

    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if(isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n",deque[rear]);

    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        rear=MAX-1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    int i=front;

    while(1)
    {
        printf("%d ",deque[i]);

        if(i==rear)
            break;

        i=(i+1)%MAX;
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