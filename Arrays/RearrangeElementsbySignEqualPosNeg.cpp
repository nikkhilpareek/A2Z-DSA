#include<bits/stdc++.h>
using namespace std;

// This code proceeds with assumption that the input will have equal number of Positives & Negatives
void  rearrangeArrayBrute(int arr[], int n){
    // Divide Array in Positives & Negatives and then rearrange.
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    // Now We have to rearrange Array in this order - Positive,negative,positive,negative....
    // Here Positives are on even index places and negatives are on odd index places
    for(int i =0; i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}

vector<int> rearrangeArrayOptimal(int arr[], int n){
    vector<int> ans(n,0);
    int posI = 0, negI = 1;
    for(int i =0; i<n; i++){
        if(arr[i]<0){
            ans[negI] = arr[i];
            negI+=2;
        }else{
            ans[posI] = arr[i];
            posI+=2;
        }
    }
    return ans;
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printVector(vector<int> arr, int n){
    for(int i = 0; i<n; i++){
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
    rearrangeArrayBrute(arr,n);
    printArray(arr,n);
    vector<int> ans = rearrangeArrayOptimal(arr,n);
    printVector(ans,n);
    return 0;
}