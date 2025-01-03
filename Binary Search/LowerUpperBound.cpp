#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int n,x;
    cout<<"Enter Element to check lower & upper bound: ";
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
    cout<<lowerBound(arr,x)<<endl;
    cout<<lower_bound(arr.begin(),arr.end(),x) - arr.begin()<<endl;
    cout<<upperBound(arr,x)<<endl;
    cout<<upper_bound(arr.begin(),arr.end(),x) - arr.begin()<<endl;
    return 0;
}