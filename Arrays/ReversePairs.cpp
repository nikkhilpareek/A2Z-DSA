#include <bits/stdc++.h>
using namespace std;

int cnt = 0; // declaring global variable count 

void countPairs(int v[], int low, int mid, int high){
    int right = mid+1;
    for(int i = low; i<=mid; i++){
        while(right<=high && v[i]>2*v[right]){
            right++;
        }
        cnt += right-(mid+1);
    }
}

void merge(int arr[], int low ,int mid, int high){
    std::vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++ ){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int l, int h) {
    if(l>=h){
        return;
    }
    int mid = (l+h)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr,mid+1, h);
    countPairs(arr,l,mid,h);
    merge(arr,l,mid,h);

}

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter Array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n);
    cout<<"Count of Reverse Pairs: "<<cnt<<endl;
    return 0;
}