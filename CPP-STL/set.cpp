#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// Set stores unique elements in sorted order

void printSet(set<int> &s){
    for(auto el: s){
        cout<<el<<" ";
    }
    cout<<endl;
}

void printMultiSet(multiset<int> &ms){
    for(auto el: ms){
        cout<<el<<" ";
    }
    cout<<endl;
}

void printUnorderedSet(unordered_set<int> &us){
        for(auto el: us){
        cout<<el<<" ";
    }
    cout<<endl;
}

int main(){
    set<int> s;
    s.insert(5); //{5}
    s.insert(51); //{5,51}
    s.insert(23); //{5,23,51}
    s.insert(12); //{5,12,23,51}
    s.insert(87); //{5,12,23,51,87}
    s.insert(23); //{5,12,23,51,87}

    //begin(), end(), rbegin(), rend(), size(), empty() & swap() works same as vectors

    s.erase(12); //{5,23,51,87} deletes 12, takes logarithmic time
    int cnt = s.count(23); // returns 1 if present, 0 if not
    printSet(s);

    //MultiSet - same as set but duplicates are allowed
    multiset<int> ms;
    ms.insert(5); //{5}
    ms.insert(51); //{5,51}
    ms.insert(23); //{5,23,51}
    ms.insert(12); //{5,12,23,51}
    ms.insert(87); //{5,12,23,51,87}
    ms.insert(23); //{5,12,23,23,51,87}
    ms.insert(23); //{5,12,23,23,23,51,87}
    ms.insert(23); //{5,12,23,23,23,23,51,87}
    ms.insert(23); //{5,12,23,23,23,23,23,51,87}
    ms.insert(23); //{5,12,23,23,23,23,23,23,51,87}

    cout<<"23 occurs "<<ms.count(23)<<" times in the Multiset"<<endl;

    //to erase a single 23
    ms.erase(ms.find(23));
    cout<<"23 occurs "<<ms.count(23)<<" times in the Multiset now"<<endl;
    
    printMultiSet(ms);
    // Unordered_set - same as set but not sorted
    unordered_set<int> us;
    us.insert(5);
    printUnorderedSet(us);
    us.insert(12);
    printUnorderedSet(us);
    us.insert(15);
    printUnorderedSet(us);
    us.insert(3);
    printUnorderedSet(us);
    us.insert(9);
    printUnorderedSet(us);

    return 0;
}