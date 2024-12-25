#include<bits/stdc++.h>
using namespace std;

void printlist(list<int> &ls){
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout<< *it <<" ";
    }
    cout<<endl;
}

int main(){
    list<int> ls; // List currently empty
    ls.push_back(2); // {2}
    ls.__emplace_back(3); //{2,3}
    ls.push_front(4); //{4,2,3}
    ls.size(); // 3
    ls.empty(); // 0 
    printlist(ls);
    //LIST HAVE SAME FUNCTIONS AS VECTOR.

    return 0;
}