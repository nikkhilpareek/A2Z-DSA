#include<bits/stdc++.h>
using namespace std;

int subarraysWithXORkBrute(int arr[], int n, int k){
    // Take all subarrays & just check
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int xr = 0;
        for(int j = i; j<n; j++){
            xr = xr xor arr[j];
            if(xr == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int subarraysWithXORkOptimal(int arr[], int n, int k){
    // Use Something Like Prefix Sum
    int xr = 0, cnt = 0;
    map<int,int> mpp;
    mpp[xr]++;
    for(int i = 0; i<n; i++){
        xr= xr^arr[i];
        int x = xr^k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    int n,k;
    cout<<"Enter Target XOR: ";
    cin>>k;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"By Brute Force Solution: "<<subarraysWithXORkBrute(arr,n,k)<<endl;
    cout<<"By Optimal Solution: "<<subarraysWithXORkOptimal(arr,n,k)<<endl;

    return 0;
}