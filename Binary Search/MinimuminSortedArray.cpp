#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &v){
    int low = 0, high = v.size()-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[low]<=v[high]){
            ans = min(ans,v[low]);
            break;
        }
        if(v[low]<=v[mid]){
            ans = min(ans, v[low]);
            low = mid+1;
        }else{
            high = mid-1;
            ans = min(ans,v[mid]);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Minimum Element in Array is: "<<findMin(arr)<<endl;
    return 0;
}