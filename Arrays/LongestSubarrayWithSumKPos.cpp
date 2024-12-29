#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKPosBrute(vector<int> v, int k){
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

int longestSubarrayWithSumKPosBetter(vector<int> v, int k){
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

int longestSubarrayWithSumKPosOptimal(vector<int> v, int k){
    int left = 0, right = 0;
    int sum = v[0];
    int maxLen = 0;
    int n = v.size();
    while(right<n){
        while(left<=right && sum>k){
            sum -= v[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n){
            sum += v[right];
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
    cout<<"By Brute Force Solution: "<<longestSubarrayWithSumKPosBrute(v,k)<<endl;
    cout<<"By Better Solution: "<<longestSubarrayWithSumKPosBetter(v,k)<<endl;
    cout<<"By Optimal Solution: "<<longestSubarrayWithSumKPosOptimal(v,k)<<endl;
    return 0;
}