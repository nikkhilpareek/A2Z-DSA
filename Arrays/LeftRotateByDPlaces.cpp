#include<bits/stdc++.h>
using namespace std;

//actual rotations needed is d%n because after every n rotations we will get the same array back.
void leftRotateBrute(int arr[], int d, int n){
    d = d%n;
    int temp[d];
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i = n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
}

void leftRotateOptimal(int arr[], int d, int n){
    // Example Array : {1,2,3,4,5,6,7,8,9,0} d=3
    reverse(arr,arr+d); // arr = {3,2,1,4,5,6,7,8,9,0}
    reverse(arr+d,arr+n); // arr = {3,2,1,0,9,8,7,6,5,4}
    reverse(arr,arr+n); // arr = {4,5,6,7,8,9,0,1,2,3}

    // This approach have higher time Complexity but lower Space Complexity
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,d;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter Places to Left Rotate: ";
    cin>>d;
    int arr[n];
    cout<<"Enter the Elements of Array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    // leftRotateBrute(arr, d, n);
    leftRotateOptimal(arr,d,n);
    printArray(arr,n);
    return 0;
}