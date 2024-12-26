#include<bits/stdc++.h>
using namespace std;

int sLargestBrute(int arr[], int n){
    sort(arr,arr+n);
    // Loop for checking if largest element have any duplicates or not, if there are duplicates we move ahead.
    for(int i = n-2; i>=0; i--){
        if(arr[i]!=arr[n-1]){
            return arr[i];
            break;
        }
    }
    return -1;
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

int sLargestBetter(int arr[],int n){
    // find Largest element first and then move ahead
    int largest = largestOptimal(arr,n);
    int secondLargest = -1; // Assuming all elements in array are positive
    for(int i = 0; i<n; i++){
        if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int sLargestOptimal(int arr[], int n){
    int largest = arr[0];
    int secondLargest = -1; 
    for(int i = 1; i<n; i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
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
    cout<<"Second largest Element by Brute Force Solution: "<<sLargestBrute(arr,n)<<endl;
    cout<<"Second largest Element by Better Solution: "<<sLargestBetter(arr,n)<<endl;
    cout<<"Second largest Element by Optimal Solution: "<<sLargestOptimal(arr,n)<<endl;
    return 0;
}