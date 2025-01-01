#include<bits/stdc++.h>
using namespace std;

vector<int> leadersBrute(int arr[], int n){
    vector<int> ans;
    for(int i =0; i<n; i++){
        bool leader = true;
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> leadersOptimal( int arr[], int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    reverse(ans.begin(), ans.end()); // to provide answer in the same order as in arr
    return ans;
}

void printVector(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    vector<int> ansBrute = leadersBrute(arr,n);
    printVector(ansBrute);
    vector<int> ansOptimal = leadersOptimal(arr,n);
    printVector(ansOptimal);
    return 0;
}