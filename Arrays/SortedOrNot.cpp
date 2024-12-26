#include<bits/stdc++.h>
using namespace std;

void checkSorted(int arr[], int n){
    int flag = 1;
    for(int i = 1; i<n; i++){
        if(arr[i]<arr[i-1]){
            flag = 0;
            break;
        }
    }
    if(flag == 1) cout<<"Array is sorted"<<endl;
    else cout<<"Array is not sorted"<<endl;
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
    checkSorted(arr,n);
    return 0;
}
