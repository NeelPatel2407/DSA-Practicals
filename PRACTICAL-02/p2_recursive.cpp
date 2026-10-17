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

int linearSearchRecursive(const vector<int>&A,int key,int index,Matrics &m)
{
    m.calls++;
    m.ops++;
    m.comparisons++;

    if(index==A.size())
    {
        return -1;
    }

    m.comparisons++;
    if(A[index]==key)
    {
        return index;
    }

    return linearSearchRecursive(A,key,index+1,m);
}

int main()
{
    vector<int>A={10,20,30,40,50,60};
    int key=40;

    Matrics m;
    m.extra_space_bytes=sizeof(int)*2;

    int result=linearSearchRecursive(A,key,0,m);

    if(result!=-1)
    {
        cout<<"Element found at index "<<result<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }

    cout<<"Comparisons: "<<m.comparisons<<endl;
    cout<<"Operations: "<<m.ops<<endl;
    cout<<"Function Calls: "<<m.calls<<endl;
    cout<<"Extra space bytes: "<<m.extra_space_bytes<<endl;

    return 0;
}