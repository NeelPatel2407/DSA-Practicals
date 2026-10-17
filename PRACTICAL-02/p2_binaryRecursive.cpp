#include<iostream>
#include<vector>
using namespace std;

struct Matrics
{
    unsigned long long comparisons=0;
    unsigned long long ops=0;
    unsigned long long calls=0;
    size_t extra_space_bytes=0;
};

int binarySearchRecursiveHelper(const vector<int>&A,int key,int low,int high,Matrics &m)
{
    m.calls++;
    m.ops++;
    m.comparisons++;

    if(low>high)
    {
        return -1;
    }

    int mid=low+(high-low)/2;
    m.ops+=3;

    m.comparisons++;
    if(A[mid]==key)
    {
        return mid;
    }

    m.comparisons++;
    if(A[mid]<key)
    {
        return binarySearchRecursiveHelper(A,key,mid+1,high,m);
    }

    return binarySearchRecursiveHelper(A,key,low,mid-1,m);
}

int binarySearchRecursive(const vector<int>&A,int key,Matrics &m)
{
    m.extra_space_bytes=3*sizeof(int)*4;
    return binarySearchRecursiveHelper(A,key,0,A.size()-1,m);
}

int main()
{
    vector<int>A={4,5,10,16,24,32,46,76,112,144,182};
    int key=46;

    Matrics m;

    int result=binarySearchRecursive(A,key,m);

    if(result!=-1)
    {
        cout<<"Element found at index "<<result<<endl;
        cout<<"Position: "<<result<<endl;
    }
    else
    {
        cout<<"Element not found..."<<endl;
    }

    cout<<"Comparisons: "<<m.comparisons<<endl;
    cout<<"Operations: "<<m.ops<<endl;
    cout<<"Function Calls: "<<m.calls<<endl;
    cout<<"Extra space bytes: "<<m.extra_space_bytes<<endl;

    return 0;
}