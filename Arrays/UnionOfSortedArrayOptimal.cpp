#include<bits/stdc++.h>
using namespace std;

vector<int> unionOptimal(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    int i = 0,j = 0;
    vector<int> unionArr;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }else{
            if(unionArr.size()==0 || unionArr.back() != b[j]){
                unionArr.push_back(b[i]);
            }
            j++;
        }
    }
    while(j<m){
        if(unionArr.size()==0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n){
        if(unionArr.size()==0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
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
    vector<int> a;
    vector<int> b;
    cout<<"Enter the Elements of Array1: ";
    for(int i =0; i<n; i++){
        int temp; 
        cin>>temp;
        a.push_back(temp);
    }
    cout<<endl;
    cout<<"Enter the Elements of Array2: ";
        for(int i =0; i<m; i++){
        int temp; 
        cin>>temp;
        b.push_back(temp);
    }
    vector<int> unionArr = unionOptimal(a,b);
    printVector(unionArr);
    return 0;
}