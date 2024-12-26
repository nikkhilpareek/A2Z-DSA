#include<bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int n){
    int temp = arr[n-1];
    for(int i = n-1; i>=0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    rightRotate(arr,n);
    printArray(arr,n);
    return 0;
}