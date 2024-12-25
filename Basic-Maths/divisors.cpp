#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n){
    vector<int> v; //using vector to print divisors in sorted order.
    for(int i = 1; i<=sqrt(n); i++){
        if(n%i==0){
            v.push_back(i);
            if((n/i) != i){
                v.push_back(n/i);
        }
    }}
    sort(v.begin(),v.end());
    cout<<"Divisors of "<<n<<" are: ";
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    printDivisors(n);
    return 0;
}