#include<iostream>
#include<vector>
using namespace std;

void countingSort(vector<int>&arr){
    int minValue=arr[0];
    int maxValue=arr[0];

    for(int i=1;i<arr.size();i++){
        if(arr[i]<minValue)
            minValue=arr[i];
        if(arr[i]>maxValue)
            maxValue=arr[i];
    }

    int range=maxValue-minValue+1;
    vector<int>count(range,0);

    for(int i=0;i<arr.size();i++)
        count[arr[i]-minValue]++;

    int index=0;

    for(int i=0;i<range;i++){
        while(count[i]>0){
            arr[index]=i+minValue;
            index++;
            count[i]--;
        }
    }
}

int main(){
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int>arr(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Original Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    countingSort(arr);

    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}