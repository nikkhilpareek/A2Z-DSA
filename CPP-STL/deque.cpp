#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    for(int i = 0; i<10; i++){
        int r = rand()%100 + 1;
        dq.push_back(r);
    }
    
    dq.push_back(1);
    dq.push_front(3);

    for(int i = 0; i<dq.size(); i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;

    dq.pop_back();
    dq.pop_front();
    for(int i = 0; i<dq.size(); i++){
        cout<<dq[i]<<" ";
    }
    return 0;
}