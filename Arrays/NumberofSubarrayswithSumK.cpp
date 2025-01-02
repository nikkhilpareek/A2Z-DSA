#include<bits/stdc++.h>
using namespace std;

int subarrayCountBrute(int arr[], int n, int k){
    int cnt = 0;
    for(int i =0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int subarrayCountOptimal(int arr[], int n, int k){
    map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i<n; i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum]++;
    }
    return cnt;
}

int main(){
    int n,k;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter target sum: ";
    cin>>k;
    cout<<"Number of Subarrays with Sum "<<k<<" by Brute force Solution is: "<<subarrayCountBrute(arr,n,k)<<endl;
    cout<<"Number of Subarrays with Sum "<<k<<" by Optimal Solution is: "<<subarrayCountBrute(arr,n,k)<<endl;
    return 0;
}