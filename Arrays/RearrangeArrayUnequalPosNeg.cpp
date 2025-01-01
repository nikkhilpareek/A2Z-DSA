#include<bits/stdc++.h>
using namespace std;

vector<int> altNumbers(vector<int> &v){
    vector<int> pos, neg;
    for(int i = 0; i<v.size(); i++){
        if(v[i]>=0){
            pos.push_back(v[i]);
        }else{
            neg.push_back(v[i]);
        }
    }

    if(pos.size()>neg.size()){
        for(int i = 0; i<neg.size(); i++){
            v[2*i] = pos[i];
            v[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i  = neg.size(); i<pos.size(); i++){
            v[index] = pos[i];
            index++;
        }
    }else{
        for(int i = 0; i<pos.size(); i++){
            v[2*i] = pos[i];
            v[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i  = pos.size(); i<neg.size(); i++){
            v[index] = neg[i];
            index++;
        }
    }
    return v;
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
    vector<int> arr;
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> ans = altNumbers(arr);
    printVector(ans,n);
    return 0;
}