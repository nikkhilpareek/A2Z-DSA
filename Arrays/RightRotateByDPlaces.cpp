#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rightRotateBrute(int arr[], int n, int d){
    int temp[d];
    // Storing Numbers to Send at the front
    for(int i = n-d; i<n; i++){
        temp[i-(n-d)] = arr[i];
    }

    // Shifting Remaining Numbers d Places ahead
    for(int i = n-1; i>=d; i--){
        arr[i] = arr[i-d];
    }

    // Adding the remaining numbers to their correct Position
    for(int i =0; i<d; i++){
        arr[i] = temp[i];
    }
}

void rightRotateOptimal(int arr[], int n, int d){
    // Example Array: {1,2,3,4,5,6,7,8,9,0} and d=3
    reverse(arr+n-d,arr+n); //{1,2,3,4,5,6,7,0,9,8}
    reverse(arr,arr+n-d); //{7,6,5,4,3,2,1,0,9,8}
    reverse(arr,arr+n); //{8,9,0,1,2,3,4,5,6,7}
}



int main(){
    int n,d;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter Places to Right Rotate: ";
    cin>>d;
    int arr[n];
    cout<<"Enter the Elements of Array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    // rightRotateBrute(arr,n,d);
    rightRotateOptimal(arr,n,d);
    printArray(arr,n);
    return 0;
}