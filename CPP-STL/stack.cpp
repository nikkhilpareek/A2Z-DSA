#include<bits/stdc++.h>
using namespace std;

// Stack is Last In First Out

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(5);
    st.push(2);
    st.push(8);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<"Size of Stack is: "<<st.size()<<endl;

    stack<int> s1,s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<"Elements in stack s1"<<endl;
    printStack(s1);
    s2.push(5);
    s2.push(6);
    s2.push(7);
    cout<<"Elements in stack s2"<<endl;
    printStack(s2);

    //Swapping the two stacks
    s1.swap(s2);
    cout<<"Elements in stack s1"<<endl;
    printStack(s1);
    cout<<"Elements in stack s2"<<endl;
    printStack(s2);
    return 0;
}