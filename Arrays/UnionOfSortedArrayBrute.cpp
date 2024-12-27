#include<bits/stdc++.h>
using namespace std;

vector<int> unionBrute(int a[], int n, int b[], int m){
    set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(a[i]);
    }
    for(int i = 0; i<m; i++){
        st.insert(b[i]);
    }
    vector<int> unionArr;
    for(auto it: st){
        unionArr.push_back(it);
    }
    return unionArr;
}

void printVector(vector<int> v){
    int n = v.size();
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cout<<"Enter the number of elements in the array1: ";
    cin>>n;
    cout<<"Enter the number of elements in the array2: ";
    cin>>m;
    int arr[n];
    int arr2[m];
    cout<<"Enter the Elements of Array1: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Enter the Elements of Array2: ";
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }
    vector<int> unionArr = unionBrute(arr, n, arr2, m);
    printVector(unionArr);
    return 0;
}