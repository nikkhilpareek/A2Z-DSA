#include<bits/stdc++.h>
using namespace std;

// this code also deals with duplicates and returns true or false depending on if the element is present or not
bool search(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k) return true;
        if(arr[low] == arr[mid] && arr[mid]==arr[high]){ // This loop deals with duplicates
            low++;
            high--;
            continue;
        }
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
    return false;
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
    if(search(arr,n,x)){
        cout<<"Element Present"<<endl;
    }else{
        cout<<"Element Not Present in Array"<<endl;
    }
    return 0;
}