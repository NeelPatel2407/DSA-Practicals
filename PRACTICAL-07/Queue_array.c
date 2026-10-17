#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("\nQueue is Overflow! Queue is Full");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("\nInserted %d at position %d", value, rear);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Underflow.Queue is empty\n");
        return;
    }
    int deletedValue = queue[front];
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    printf("\n%d is deleted from queue.\n", deletedValue);
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty.");
        return;
    }
    printf("Front Element is %d", queue[front]);
}

void Display()
{
    if (isEmpty())
    {
        printf("Queue is Empty.");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Exiting ...! \n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}