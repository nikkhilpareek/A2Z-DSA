#include<bits/stdc++.h>
using namespace std;

// This Code Assumes that the elements in the given array is Unique
int search(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k) return mid;
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid+1;
            }else{
                high = mid-1;
        }
        }
    }
    return -1;
}

int main(){
    int n,x;
    cout<<"Enter Target Element: ";
    cin>>x;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Index is: "<<search(arr,n,x)<<endl;
    return 0;
}