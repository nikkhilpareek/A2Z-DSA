#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] != arr[mid]+1 && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"The Single Element in Array is: "<<singleElement(arr)<<endl;
    return 0;
}