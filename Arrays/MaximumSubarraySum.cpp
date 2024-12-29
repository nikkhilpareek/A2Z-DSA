#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumBrute(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int maxSubarraySumOptimal(int arr[], int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start, ansStart, end;
    for(int i = 0; i<n; i++){
        if(sum == 0) {
            start = i;
        }
        sum+=arr[i];
        if(sum>maxi){
            maxi = sum;
            ansStart = start, end = i;
        }
        if(sum<0){
            sum = 0;
        }
    }

    // If asked to print subarray - run a loop from ansStart to end.

    return maxi;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of Array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSubarraySumBrute(arr,n)<<endl;
    cout<<maxSubarraySumOptimal(arr,n)<<endl;
    return 0;
}