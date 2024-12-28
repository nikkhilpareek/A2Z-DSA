#include<bits/stdc++.h>
using namespace std;

int findMissingNumBrute(int arr[], int n){
    for(int i = 1; i<=n; i++){
        int flag=0;
        for(int j = 0; j<n-1; j++){
            if(arr[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

int findMissingNumBetter(int arr[], int n){
    vector<int> hash(n+1,0);
    for(int i = 0; i<n-1; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i<=n; i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}

int findMissingNumOptimalA(int arr[], int n){
    long long sum = (n*(n+1))/2; // as this can have a very large result we are using long long
    long long sum2 = 0;
    for(int i = 0; i<n-1; i++){
        sum2 += arr[i];
    }
    return sum-sum2;
}

int findMissingNumOptimalB(int arr[], int n){
    // a xor a = 0
    // a xor 0 = a
    int xor1 = n,xor2 = 0;
    for(int i = 0; i<n-1; i++){
        xor2 = xor2 xor arr[i];
        xor1 = xor1 xor (i+1);
    }
    return xor1 xor xor2;
}

int main(){
    int N;
    cout<<"Enter N (The Largest Possible Number in Array): "; // if N = 5, Array can have elements from this: {1,2,3,4,5} 
    cin>>N;
    int arr[N-1];
    cout<<"Enter the "<<N-1<<" Elements of Array : ";
    for(int i =0; i<N-1; i++){
        cin>>arr[i];
    }
    cout<<findMissingNumBrute(arr,N)<<endl;
    cout<<findMissingNumBetter(arr,N)<<endl;
    cout<<findMissingNumOptimalA(arr,N)<<endl;
    cout<<findMissingNumOptimalB(arr,N)<<endl;
    return 0;
}