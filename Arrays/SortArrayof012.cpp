#include<bits/stdc++.h>
using namespace std;


// This is also called Dutch National Flag Algorithm.
void sortArray012(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
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
    sortArray012(arr,n);
    printArray(arr,n);
    return 0;
}