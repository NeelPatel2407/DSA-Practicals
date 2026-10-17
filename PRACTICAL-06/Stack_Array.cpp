#include<iostream>
using namespace std;

#define MAX 5

int arr[MAX];
int top=-1;

void push(int value)
{
    if(top==MAX-1)
    {
        cout<<"Stack Overflow cannot push "<<value<<endl;
        return;
    }

    top++;
    arr[top]=value;
    cout<<value<<" pushed into the stack"<<endl;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow Stack is empty"<<endl;
        return;
    }

    cout<<arr[top]<<" popped from the stack"<<endl;
    top--;
}

void peek()
{
    if(top==-1)
    {
        cout<<"Stack Underflow Stack is empty"<<endl;
        return;
    }

    cout<<"Top element is: "<<arr[top]<<endl;
}

void display()
{
    if(top==-1)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    cout<<"Stack Elements are:"<<endl;

    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        cout<<"\n1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter value to push: ";
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
                return 0;

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}