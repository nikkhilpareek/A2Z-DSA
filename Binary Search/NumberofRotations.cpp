#include<bits/stdc++.h>
using namespace std;

int findRotations(vector<int> &v){
    int low = 0, high = v.size()-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[low]<=v[high]){
            if(v[low]<ans){
                ans  = low;
            }
            break;
        }
        if(v[low]<=v[mid]){
            if(ans<v[mid]){
                ans = low;
            }
            low = mid+1;
        }else{
            high = mid-1;
            if(ans<v[mid]){
                ans = mid;
            }
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
    cout<<"Number of Rotations in Array is: "<<findRotations(arr)<<endl;
    return 0;
}