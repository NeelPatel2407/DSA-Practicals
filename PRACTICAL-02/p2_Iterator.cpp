#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i;
    }

    return -1;
}

int main()
{
    int arr[]={10,20,30,40,50,60};
    int size=6;
    int key;

    cout<<"Enter element to search: ";
    cin>>key;

    int result=linearSearch(arr,size,key);

    if(result==-1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at index "<<result;
    }

    return 0;
}