#include<bits/stdc++.h>
using namespace std;

// Binary Search is only used in Sorted Areas
int binarySearch(vector<int> &v, int target){
    int low = 0, high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid] == target) return mid; //found
        else if(target>v[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1; // not found
}

int recursiveBinarySearch(vector<int> &v,int low, int high, int target){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(v[mid] == target){
        return mid;
    }else if(target>v[mid]){
        return recursiveBinarySearch(v,mid+1,high, target);
    }
    return recursiveBinarySearch(v,low,mid-1,target);
}

int main(){
    int n,target;
    cout<<"Enter Target Element: ";
    cin>>target;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<binarySearch(arr,target)<<endl;
    cout<<recursiveBinarySearch(arr,0,n,target);
    return 0;
}
