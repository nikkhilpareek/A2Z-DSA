#include<bits/stdc++.h>
using namespace std;

void printMap(map<int,int> &mpp){
    for(auto it:mpp){
        cout<<"{"<<it.first<<" "<<it.second<<"}"<<" ";
    }
    cout<<endl;
}

int main(){
    map<int,int> mpp; // Stored in sorted order
    mpp[1] = 2;
    mpp[5] = 4;
    mpp[10] = 9;
    mpp[6] = 12;
    printMap(mpp);

    // Multimap - same as map but can have multiple keys, example: {1,3} & {1,5} can be present in the same multimap.
    // unordered_map - same difference as set 7 unordered_set
    return 0;
}