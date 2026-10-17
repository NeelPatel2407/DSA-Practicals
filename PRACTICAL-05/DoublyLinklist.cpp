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

int isEmpty()
{
    return head==NULL;
}

void displayForward()
{
    if(head==NULL)
    {
        cout<<"\nList is Empty"<<endl;
        return;
    }

    Node* temp=head;

    cout<<"\nForward List:"<<endl;
    cout<<"NULL <- ";

    while(temp!=NULL)
    {
        cout<<"["<<temp->data<<"]";

        if(temp->next!=NULL)
            cout<<"<->";

        temp=temp->next;
    }

    cout<<" -> NULL"<<endl;
}

void displayBackward()
{
    if(head==NULL)
    {
        cout<<"\nList is Empty"<<endl;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    cout<<"\nBackward List:"<<endl;
    cout<<"NULL <- ";

    while(temp!=NULL)
    {
        cout<<"["<<temp->data<<"]";

        if(temp->prev!=NULL)
            cout<<"<->";

        temp=temp->prev;
    }

    cout<<" -> NULL"<<endl;
}

void insertAtBeginning(int value)
{
    Node* newNode=createNode(value);

    newNode->next=head;

    if(head!=NULL)
        head->prev=newNode;

    head=newNode;

    cout<<"\n"<<value<<" inserted at Beginning"<<endl;
}

void insertAtEnd(int value)
{
    Node* newNode=createNode(value);

    if(head==NULL)
    {
        head=newNode;
        cout<<"\n"<<value<<" inserted as the first node"<<endl;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;

    cout<<"\n"<<value<<" inserted at End"<<endl;
}

void insertAtPosition(int value,int position)
{
    if(position<=0)
    {
        cout<<"\nPosition must be greater than 0"<<endl;
        return;
    }

    if(position==1)
    {
        insertAtBeginning(value);
        return;
    }

    Node* temp=head;
    int currentPosition=1;

    while(temp!=NULL&&currentPosition<position-1)
    {
        temp=temp->next;
        currentPosition++;
    }

    if(temp==NULL)
    {
        cout<<"\nInvalid position"<<endl;
        return;
    }

    Node* newNode=createNode(value);

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;

    cout<<"\n"<<value<<" inserted at position "<<position<<endl;
}

void deleteFromBeginning()
{
    if(head==NULL)
    {
        cout<<"\nList is Empty, Nothing to delete..."<<endl;
        return;
    }

    Node* temp=head;

    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    cout<<"\n"<<temp->data<<" deleted from Beginning"<<endl;

    delete temp;
}

void deleteFromEnd()
{
    if(head==NULL)
    {
        cout<<"\nList is Empty, Nothing to delete..."<<endl;
        return;
    }

    Node* temp=head;

    if(temp->next==NULL)
    {
        cout<<"\n"<<temp->data<<" deleted from End"<<endl;
        delete temp;
        head=NULL;
        return;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->prev->next=NULL;

    cout<<"\n"<<temp->data<<" deleted from End"<<endl;

    delete temp;
}

void deleteByValue(int value)
{
    if(head==NULL)
    {
        cout<<"\nList is Empty, Nothing to delete..."<<endl;
        return;
    }

    Node* temp=head;

    while(temp!=NULL&&temp->data!=value)
        temp=temp->next;

    if(temp==NULL)
    {
        cout<<"\n"<<value<<" not found in the list"<<endl;
        return;
    }

    if(temp==head)
    {
        head=temp->next;

        if(head!=NULL)
            head->prev=NULL;

        cout<<"\n"<<value<<" deleted from the list"<<endl;
        delete temp;
        return;
    }

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    temp->prev->next=temp->next;

    cout<<"\n"<<value<<" deleted from the list"<<endl;

    delete temp;
}

void reversePrint()
{
    if(head==NULL)
    {
        cout<<"\nList is Empty"<<endl;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    cout<<"\nReverse List:"<<endl;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }

    cout<<endl;
}

int main()
{
    insertAtBeginning(20);
    insertAtBeginning(10);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtPosition(25,3);

    displayForward();
    displayBackward();

    deleteFromBeginning();
    displayForward();

    deleteFromEnd();
    displayForward();

    deleteByValue(25);
    displayForward();

    reversePrint();

    return 0;
}