#include<iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

Node* frontNode=NULL;
Node* rearNode=NULL;

void insertRear(int token)
{
    Node* newNode=new Node;
    newNode->token=token;
    newNode->next=NULL;

    if(frontNode==NULL)
    {
        frontNode=rearNode=newNode;
    }
    else
    {
        rearNode->next=newNode;
        rearNode=newNode;
    }
}

void deleteByValue(int token)
{
    if(frontNode==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    if(frontNode->token==token)
    {
        Node* temp=frontNode;
        frontNode=frontNode->next;

        if(frontNode==NULL)
            rearNode=NULL;

        delete temp;
        return;
    }

    Node* temp=frontNode;

    while(temp->next!=NULL && temp->next->token!=token)
        temp=temp->next;

    if(temp->next==NULL)
    {
        cout<<"Token not found"<<endl;
        return;
    }

    Node* del=temp->next;
    temp->next=del->next;

    if(del==rearNode)
        rearNode=temp;

    delete del;
}

void displayForward()
{
    Node* temp=frontNode;

    if(temp==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    while(temp!=NULL)
    {
        cout<<temp->token<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

void displayReverse(Node* temp)
{
    if(temp==NULL)
        return;

    displayReverse(temp->next);
    cout<<temp->token<<" ";
}

int main()
{
    insertRear(101);
    insertRear(102);
    insertRear(103);
    insertRear(104);
    insertRear(105);

    cout<<"Forward queue: ";
    displayForward();

    deleteByValue(103);

    cout<<"After deletion: ";
    displayForward();

    cout<<"Reverse queue: ";
    displayReverse(frontNode);
    cout<<endl;

    return 0;
}