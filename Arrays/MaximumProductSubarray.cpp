#include<bits/stdc++.h>
using namespace std;

// Brute Force - Generate all subarray and check

int subarrayMaxProd(vector<int> &arr){
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre = pre*arr[i];
        suff = suff*arr[n-i-1];
        ans = max(ans, max(pre,suff));
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<"Maximum Subarray Product is: "<<subarrayMaxProd(v)<<endl;
    return 0;
}