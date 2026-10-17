#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head=NULL;

Node* createNode(int value)
{
    Node* newNode=new Node;

    newNode->data=value;
    newNode->next=NULL;

    return newNode;
}

void insertAtPosition(int value,int position)
{
    Node* newNode=createNode(value);

    if(position<=0)
    {
        cout<<"Invalid position"<<endl;
        delete newNode;
        return;
    }

    if(head==NULL)
    {
        if(position!=1)
        {
            cout<<"Invalid position"<<endl;
            delete newNode;
            return;
        }

        head=newNode;
        newNode->next=head;
        return;
    }

    if(position==1)
    {
        Node* last=head;

        while(last->next!=head)
            last=last->next;

        newNode->next=head;
        last->next=newNode;
        head=newNode;
        return;
    }

    Node* temp=head;
    int i=1;

    while(i<position-1)
    {
        temp=temp->next;
        i++;

        if(temp==head)
        {
            cout<<"Invalid position"<<endl;
            delete newNode;
            return;
        }
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteValue(int value)
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=head;
    Node* prev=NULL;

    do
    {
        if(temp->data==value)
            break;

        prev=temp;
        temp=temp->next;
    }
    while(temp!=head);

    if(temp->data!=value)
    {
        cout<<"Value not found"<<endl;
        return;
    }

    if(temp==head)
    {
        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            Node* last=head;

            while(last->next!=head)
                last=last->next;

            head=head->next;
            last->next=head;
        }
    }
    else
    {
        prev->next=temp->next;
    }

    delete temp;
}

void display()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=head;

    cout<<"Singly Circular List: ";

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);

    cout<<endl;
}

int main()
{
    int choice,value,position;

    while(1)
    {
        cout<<"\n1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>value;

                cout<<"Enter position: ";
                cin>>position;

                insertAtPosition(value,position);
                display();
                break;

            case 2:
                cout<<"Enter value to delete: ";
                cin>>value;

                deleteValue(value);
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}