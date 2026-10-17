#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head=NULL;

Node* createNode(int value)
{
    Node* newNode=new Node;

    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode;
}

void insertAtPosition(int value,int position)
{
    Node* newNode=createNode(value);

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
        newNode->prev=head;
        return;
    }

    if(position==1)
    {
        Node* last=head->prev;

        newNode->next=head;
        newNode->prev=last;

        last->next=newNode;
        head->prev=newNode;

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
    newNode->prev=temp;

    temp->next->prev=newNode;
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

    do
    {
        if(temp->data==value)
        {
            break;
        }

        temp=temp->next;
    }
    while(temp!=head);

    if(temp->data!=value)
    {
        cout<<"Value not found"<<endl;
        return;
    }

    if(temp->next==temp)
    {
        head=NULL;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        if(temp==head)
        {
            head=temp->next;
        }
    }

    delete temp;
}

void displayForward()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=head;

    cout<<"Doubly Circular List: ";

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);

    cout<<endl;
}

void displayBackward()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=head->prev;

    cout<<"Reverse List: ";

    do
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    while(temp!=head->prev);

    cout<<endl;
}

int main()
{
    int choice,value,position;

    while(1)
    {
        cout<<"\n1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Forward Display"<<endl;
        cout<<"4. Backward Display"<<endl;
        cout<<"5. Exit"<<endl;
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
                displayForward();
                break;

            case 2:
                cout<<"Enter value to delete: ";
                cin>>value;

                deleteValue(value);
                displayForward();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                return 0;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}