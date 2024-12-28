#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> v){
    int maxi = 0;
    int cnt = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i]==1){
            cnt++;
            maxi = max(cnt,maxi);
        }else{
            cnt=0;
        }
    }
    return maxi;
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
    cout<<"The Given Array have "<<maxConsecutiveOnes(a)<<" ones in it.";
    return 0;
}