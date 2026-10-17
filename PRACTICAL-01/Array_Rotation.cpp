#include<iostream>
using namespace std;

int main()
{
    int n,h,k,i;
    string item[50];

    cout<<"Enter number of items: ";
    cin>>n;

    cout<<"Enter the name of items: ";
    for(i=0;i<n;i++)
    {
        cin>>item[i];
    }

    cout<<"Enter number of hours: ";
    cin>>h;

    k=h%n;

    cout<<"Final display hours: ";

    for(i=k;i<n;i++)
    {
        cout<<item[i]<<" ";
    }

    for(i=0;i<k;i++)
    {
        cout<<item[i]<<" ";
    }

    return 0;
}