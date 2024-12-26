#include<bits/stdc++.h>
using namespace std;

int largestBrute(int arr[], int n){
    // Brute Force Approach - Sort the array and return element at index (n-1)
    // Using sort STL for Sorting
    sort(arr,arr+n);
    return(arr[n-1]);
}

int largestOptimal(int arr[], int n){
    int largest = arr[0];
    for(int i =1; i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
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
    cout<<"Largest Element by Brute Force Solution: "<<largestBrute(arr,n)<<endl;
    cout<<"Largest Element by Optimal Solution: "<<largestOptimal(arr,n)<<endl;
    return 0;
}