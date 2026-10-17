#include<iostream>
using namespace std;

int main()
{
    int n,i,j,id[100],count;
    int foundDuplicate=0,alreadyprint;

    cout<<"Enter the number of books: ";
    cin>>n;

    cout<<"Enter book IDs: ";
    for(i=0;i<n;i++)
    {
        cin>>id[i];
    }

    for(i=0;i<n;i++)
    {
        count=0;
        alreadyprint=0;

        for(j=0;j<i;j++)
        {
            if(id[i]==id[j])
            {
                alreadyprint=1;
                break;
            }
        }

        if(alreadyprint==1)
        {
            continue;
        }

        for(j=0;j<n;j++)
        {
            if(id[i]==id[j])
            {
                count++;
            }
        }

        if(count>1)
        {
            cout<<id[i]<<" ";
            foundDuplicate=1;
        }
    }

    if(foundDuplicate==0)
    {
        cout<<"No duplicate";
    }

    return 0;
}