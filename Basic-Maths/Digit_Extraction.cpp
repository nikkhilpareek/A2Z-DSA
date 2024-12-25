#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void printDig(int n){
    stack<int> st; //Using stack to print digits in correct order example - n = 12345, digs = 1 2 3 4 5
    while(n>0){
        st.push(n%10);
        n /= 10;
    }
    printStack(st);
}

int main(){
    int n;
    cin>>n;
    printDig(n);
    return 0;
}
