#include<iostream>
using namespace std;

int main()
{
    int n,i,j,temp;
    int arr[100];

    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"Sorted order: ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}