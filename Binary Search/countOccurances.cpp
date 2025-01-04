#include<bits/stdc++.h>
using namespace std;

// Simply use last Occurance - first Occurance + 1

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

pair<int,int> firstLastBest(vector<int> &v, int target){
    // We Will use C++ STL for this method
    int n = v.size();
    pair<int,int> ans;
    int lb = lowerBound(v,target);
    if(lb == n || v[lb] != target){
        ans.first = -1;
        ans.second = -1;
        return ans;
    }
    int ub = upperBound(v,target);
    ans.first = lb;
    ans.second = ub-1;
    return ans;
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
    pair<int,int> ans = firstLastBest(arr,x);
    cout<<"Count of Occurances is: "<<ans.second-ans.first+1<<endl;
    return 0;
}