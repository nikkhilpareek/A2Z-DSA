#include<bits/stdc++.h>
using namespace std;

// Queue is First In First Out

void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void printPQ(priority_queue<int> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

void printMinHeap(priority_queue<int,vector<int>, greater<int> > pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}


int main(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.push(3); // {1,2,3}
    q.back()+=5; // {1,2,8}
    printQueue(q);
    //size, swap and empty works the same as in stack.

    priority_queue<int> pq;
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.push(10); //{10,8,5,2}
    printPQ(pq);
    //size, swap and empty works the same as in stack.

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int> > mh;
    mh.push(5); //{5}
    mh.push(8); //{5,8}
    mh.push(12); //{5,8,12}
    mh.push(4);  //{4,5,8,12}
    mh.push(2); //{2,4,5,8,12} 
    printMinHeap(mh);
    return 0;
}