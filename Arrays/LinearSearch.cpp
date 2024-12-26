#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n, int x){
    // If x have duplicates, it will return the index of First occurence.
    for(int i = 0; i<n; i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,x;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the Number to find: ";
    cin>>x;
    int arr[n];
    cout<<"Enter the Elements of Array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int index = linearSearch(arr,n,x);
    if(index==-1){
        cout<<"Element not Found"<<endl;
    }else{
        cout<<"Element Found at Index: "<<index<<endl;
    }
    return 0;
}