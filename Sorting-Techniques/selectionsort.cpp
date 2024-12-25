#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n){
    for(int i = 0; i<=n-1; i++){
        int mini = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter Array Elements";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}