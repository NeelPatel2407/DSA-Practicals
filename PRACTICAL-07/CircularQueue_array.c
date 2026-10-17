#include<stdio.h>

#define MAX 5

typedef struct
{
    int data[MAX];
    int front,rear,count;
}CircularQueue;

void initialize(CircularQueue *q)
{
    q->front=-1;
    q->rear=-1;
    q->count=0;
}

int isFull(CircularQueue *q)
{
    return q->count==MAX;
}

int isEmpty(CircularQueue *q)
{
    return q->count==0;
}

void enqueue(CircularQueue *q,int value)
{
    if(isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty(q))
    {
        q->front=0;
        q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%MAX;
    }

    q->data[q->rear]=value;
    q->count++;
}

void dequeue(CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n",q->data[q->front]);

    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=(q->front+1)%MAX;
    }

    q->count--;
}

void peekFront(CircularQueue *q)
{
    if(isEmpty(q))
        printf("Queue is Empty\n");
    else
        printf("Front: %d\n",q->data[q->front]);
}

void peekRear(CircularQueue *q)
{
    if(isEmpty(q))
        printf("Queue is Empty\n");
    else
        printf("Rear: %d\n",q->data[q->rear]);
}

void display(CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    int i=q->front;

    while(1)
    {
        printf("%d ",q->data[i]);

        if(i==q->rear)
            break;

        i=(i+1)%MAX;
    }

    printf("\n");
}

int main()
{
    CircularQueue q;
    int choice,value;

    initialize(&q);

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
                enqueue(&q,value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                peekFront(&q);
                break;

            case 4:
                peekRear(&q);
                break;

            case 5:
                display(&q);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}