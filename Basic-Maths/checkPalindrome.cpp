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

void checkPalindrome(int n){
    if(n==revNum(n)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    checkPalindrome(n);
    return 0;
}