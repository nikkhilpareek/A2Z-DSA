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

int firstOccurence(vector<int> &arr,int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            first =mid;
            high = mid-1;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return first;
}

int lastOccurance(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            last =mid;
            low = mid+1;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return last;
}

pair<int,int> firstLastOccuranceBS(vector<int> arr, int target){
    pair<int,int> ans;
    ans.first = firstOccurence(arr,target);
    if(ans.first == -1 || ans.first == arr.size()){
        ans.first = -1;
        ans.second = -1;
        return ans;
    }
    ans.second = lastOccurance(arr,target);
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
    cout<<"First Occurance at Index: "<<ans.first<<" Second Occurence at Index: "<<ans.second<<endl;
    pair<int,int> ans2 = firstLastOccuranceBS(arr,x);
    cout<<"First Occurance at Index: "<<ans2.first<<" Second Occurence at Index: "<<ans2.second<<endl;
    return 0;
}