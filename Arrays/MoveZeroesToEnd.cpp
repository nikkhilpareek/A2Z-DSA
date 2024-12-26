#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroesBrute(vector<int> &v){
    int n = v.size();
    vector<int> temp;
    for(int i = 0; i<n; i++){
        if(v[i]!=0){
            temp.push_back(v[i]);
        }
    }
    int nz = temp.size();
    for(int i = 0; i<nz; i++){
        v[i] = temp[i];
    }
    for(int i = nz; i<n; i++){
        v[i] = 0;
    }
    return v;
}

vector<int> moveZeroesOptimal(vector<int> &v){
    int n = v.size();
    int j = -1;
    for(int i = 0; i<n; i++){
        if(v[i] == 0){
            j = i;
            break;
        }
    }
    // if no non-zero numbers
    if(j==-1){
        return v;
    }

    for(int i = j+1; i<n; i++){
        if(v[i]!=0){
            swap(v[i],v[j]);
            j++;
        }
    }
    return v;
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
    // moveZeroesBrute(v);
    moveZeroesOptimal(v);
    printVector(v);
    return 0;
}