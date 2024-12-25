// Quick Sort

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<= high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void qS(int arr[], int low, int high){
    if(low<high){
        int partition_Index = partition(arr, low, high);
        qS(arr, low, partition_Index-1);
        qS(arr,partition_Index+1, high);
    }
}

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter Array Elements";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    qS(arr,0,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}