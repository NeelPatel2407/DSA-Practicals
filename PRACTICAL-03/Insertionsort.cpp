#include<iostream>
using namespace std;

int main()
{
    int n,i,j,key;
    int arr[100];

    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }

    cout<<"Sorted order: ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}