#include<bits/stdc++.h>
using namespace std;

int revNum(int n){
    int revN = 0;
    while(n>0){
        int ld = n%10;
        n /= 10;
        revN = revN*10 + ld;
    }
    return revN;
}

int main(){
    int n;
    cin>>n;
    cout<<revNum(n)<<endl;
    return 0;
}