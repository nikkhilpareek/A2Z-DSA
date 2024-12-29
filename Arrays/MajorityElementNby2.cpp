#include<bits/stdc++.h>
using namespace std;

int majorityElementOptimal(int arr[], int n){
    int cnt = 0;
    int el;
    for(int i = 0; i<n; i++){
        if(cnt==0){
            cnt = 1;
            el = arr[i];
        }else if(arr[i] == el){
            cnt++;
        }else{
            cnt--;
        }
    }
    cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == el){
            cnt++;
        }
    }
    if(cnt>n/2){
        return el;
    }
    return -1;
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
    cout<<"Majority Element is: "<<majorityElementOptimal(arr,n)<<endl;
    return 0;
}