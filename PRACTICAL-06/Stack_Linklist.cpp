#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top=NULL;

Node* createNode(int value)
{
    Node* newNode=new Node;

    newNode->data=value;
    newNode->next=NULL;

    return newNode;
}

void push(int value)
{
    Node* newNode=createNode(value);

    newNode->next=top;
    top=newNode;

    cout<<value<<" pushed into the stack"<<endl;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow! Stack is empty"<<endl;
        return;
    }

    Node* temp=top;
    int deleteValue=top->data;

    top=top->next;
    delete temp;

    cout<<deleteValue<<" popped from the stack"<<endl;
}

void peek()
{
    if(top==NULL)
    {
        cout<<"Stack is empty, no top element"<<endl;
        return;
    }

    cout<<"Top element is: "<<top->data<<endl;
}

void display()
{
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    Node* temp=top;

    cout<<"Stack elements from top to bottom:"<<endl;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        cout<<"\nStack using Linked List"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout<<"Program exited"<<endl;
                return 0;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}