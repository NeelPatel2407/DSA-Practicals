#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void display(Node* head)
{
    if(head==NULL)
    {
        cout<<"Queue is empty."<<endl;
        return;
    }

    Node* temp=head;
    cout<<"Current Queue: ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

void insertFront(Node*& head,int value)
{
    Node* newNode=createNode(value);
    newNode->next=head;
    head=newNode;
}

void insertEnd(Node*& head,int value)
{
    Node* newNode=createNode(value);

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}

void insertAtPosition(Node*& head,int value,int position)
{
    if(position<1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(position==1)
    {
        insertFront(head,value);
        return;
    }

    Node* temp=head;

    for(int i=1;i<position-1;i++)
    {
        if(temp==NULL)
        {
            cout<<"Invalid Position! Position is beyond queue length."<<endl;
            return;
        }

        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Invalid Position! Position is beyond queue length."<<endl;
        return;
    }

    Node* newNode=createNode(value);
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteByValue(Node*& head,int value)
{
    if(head==NULL)
    {
        cout<<"Queue is empty. Deletion not possible."<<endl;
        return;
    }

    Node* temp=head;

    if(temp->data==value)
    {
        head=temp->next;
        delete temp;
        cout<<"Patient Token deleted."<<endl;
        return;
    }

    Node* prev=NULL;

    while(temp!=NULL&&temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Patient token not found."<<endl;
        return;
    }

    prev->next=temp->next;
    delete temp;

    cout<<"Patient token deleted."<<endl;
}

void reversePrint(Node* head)
{
    if(head==NULL)
        return;

    reversePrint(head->next);
    cout<<head->data<<" ";
}

int main()
{
    Node* head=NULL;
    int choice,token,position;

    while(1)
    {
        cout<<"\n---Hospital Patient Queue---"<<endl;
        cout<<"1. Insert Critical Patient at Front"<<endl;
        cout<<"2. Insert Routine Patient at End"<<endl;
        cout<<"3. Insert Priority Patient at Position"<<endl;
        cout<<"4. Display Queue Forward"<<endl;
        cout<<"5. Display Queue Reverse"<<endl;
        cout<<"6. Delete Patient Token"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter patient Token: ";
                cin>>token;
                insertFront(head,token);
                display(head);
                break;

            case 2:
                cout<<"Enter patient Token: ";
                cin>>token;
                insertEnd(head,token);
                display(head);
                break;

            case 3:
                cout<<"Enter patient Token: ";
                cin>>token;
                cout<<"Enter Position: ";
                cin>>position;
                insertAtPosition(head,token,position);
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                if(head==NULL)
                {
                    cout<<"Queue is empty."<<endl;
                }
                else
                {
                    cout<<"Queue from last to first: ";
                    reversePrint(head);
                    cout<<endl;
                }
                break;

            case 6:
                cout<<"Enter Token to delete: ";
                cin>>token;
                deleteByValue(head,token);
                display(head);
                break;

            case 7:
                return 0;

            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }

    return 0;
}