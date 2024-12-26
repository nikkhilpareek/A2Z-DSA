#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotate(vector<int> &arr){
    int n = arr.size();
    int temp = arr[0];
    for(int i = 1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

void printVector(vector<int> v){
    int n = v.size();
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    cout<<"Enter Number of elements in array: ";
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int temp; 
        cin>>temp;
        v.push_back(temp);
    }
    leftRotate(v);
    printVector(v);
    return 0;
}