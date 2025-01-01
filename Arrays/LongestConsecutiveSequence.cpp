#include<bits/stdc++.h>
using namespace std;

// arr[] = [102,4,100,1,101,3,2,1,1] 
// answer would be - [1,2,3,4] as it is sequence not subarray. Repeatition is not allowed.
// Code Returns the length of the longest sequence possible

int longestSequenceBetter(int arr[], int n){
    sort(arr,arr+n);
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i = 0; i<n; i++){
        if(arr[i]-1 == lastSmaller){
            cnt++;
            lastSmaller = arr[i];
        }else if(lastSmaller != arr[i]){
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}

int longestSequenceOptimal(int arr[], int n){
    int longest = 1;
    set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(arr[i]);
    }
    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" By Better Solution: "<<longestSequenceBetter(arr,n)<<" By Optimal Solution: "<<longestSequenceOptimal(arr,n)<<endl;
    return 0;
}