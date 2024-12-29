#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKBrute(vector<int> v, int k){
    // Brute Force Approach - Generate All Subarrays & check the sum.
    int len = 0;
    int n = v.size();
    for(int i = 0; i<n; i++){
        int sum=0;
        for(int j = i; j<n; j++){
            sum += v[j];
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

int longestSubarrayWithSumKOptimal(vector<int> v, int k){
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i];
        if(sum==k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    int n,k;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> v;
    for(int i =0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<"Enter the Sum to Check: ";
    cin>>k;
    cout<<"By Brute Force Solution: "<<longestSubarrayWithSumKBrute(v,k)<<endl;
    cout<<"By Optimal Solution: "<<longestSubarrayWithSumKOptimal(v,k)<<endl;
    return 0;
}