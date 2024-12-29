#include<bits/stdc++.h>
using namespace std;

void twoSumIndexBrute(int arr[], int n, int target){
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                cout<<"Target Sum Found at Indexes: "<<i<<" & "<<j<<endl;
                return;
            }
        }
    }
    cout<<"Target Sum not found in given array"<<endl;
}

void twoSumIndexOptimal(int arr[], int n, int target){
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            cout<<"Target Sum Found at Indexes: "<<mpp[a]<<" & "<<mpp[more]<<endl;
            return;
        }
        mpp[a] = i;
    }
    cout<<"Target Sum not found in given array"<<endl;
}

int main(){
    int n,target;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target Element: ";
    cin>>target;
    twoSumIndexBrute(arr, n, target);
    twoSumIndexBrute(arr, n, target);
    return 0;
}