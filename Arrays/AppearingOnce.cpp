#include<bits/stdc++.h>
using namespace std;

int appearingOnce(vector<int> v,int n){
    int xor1 = 0;
    for(int i = 0; i<n; i++){
        xor1 = xor1 xor v[i];
    }
    return xor1;
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> a;
    
    cout<<"Enter Elements of  Array: ";
    for(int i =0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cout<<"The Number that appears only once in the array is: "<<appearingOnce(a,n)<<endl;
    return 0;
}