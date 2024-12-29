#include<bits/stdc++.h>
using namespace std;

string twoSumYNBrute(int arr[], int n, int target){
    string result = "No, Target cannot be achieved by adding two elements in the given array";
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                result = "Yes, The Target Sum can be achieved by adding two elements of the array";
            }
        }
    }
    return result;
}

string twoSumYNBetter(int arr[], int n, int target){
    // Optimal if we have to return the Index of the Two Elements.
    string result = "No, Target cannot be achieved by adding two elements in the given array";
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            result = "Yes, The Target Sum can be achieved by adding two elements of the array";
        }
        mpp[a] = i;
    }
    return result;
}

string twoSumYNOptimal(int arr[], int n, int target){
    // Using 2 Pointer Approach, Optimal if we have to return only yes or no. 
    // in case we need to return index, use better solution given above.
    string result = "No, Target cannot be achieved by adding two elements in the given array";
    sort(arr,arr+n);
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            result = "Yes, The Target Sum can be achieved by adding two elements of the array";
            break; // to avoid an infinite loop after we find our target sum.
        }else if(sum<target){
            left++;
        }else{
            right--;
        }
    }
    return result;
}

int main(){
    int n,target;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target Element: ";
    cin>>target;
    cout<<twoSumYNBrute(arr, n, target)<<endl;
    cout<<twoSumYNBetter(arr, n, target)<<endl;
    cout<<twoSumYNOptimal(arr, n, target)<<endl;
    return 0;
}