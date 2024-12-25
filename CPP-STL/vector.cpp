#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void vecPrintIterator(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }
    cout<<endl;
}

void vecPrintAuto(vector<int> &v){
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(1); // adds 1 to the end of the vector
    v.__emplace_back(5); //adds 5 to the end of the vector but faster than push_back
    printvector(v); // function to print a vector<int>

    // different functions to print vector
    vector<int> vec(10,100); // adds 100 five times in the vector
    printvector(vec);
    vecPrintIterator(vec); //prints using iterators
    vecPrintAuto(vec); //may generate warnings but works absolutely fine. 


    // Generating a vector with random inputs
    vector<int> vecc;
    for(int i = 0; i<10; i++){
        int r = rand()%100 + 1;
        vecc.push_back(r);
    }

    // deletion in vector
    printvector(vecc); // A vector with random inputs from 1 to 100
    vecc.erase(vecc.begin()+3); // erases element in vector at index = 3
    printvector(vecc);
    vecc.erase(vecc.begin()+1, vecc.begin()+3); // deletes element in the range
    printvector(vecc);

    // Insert in a vector
    vector<int> inV(2,100); // vector is {100,100}
    printvector(inV);
    inV.insert(inV.begin(),300); // vector is now {300,100,100}
    printvector(inV);
    inV.insert(inV.begin()+1, 2,10); //vector is now {300,10,10,100,100}
    printvector(inV);
    vector<int> newV(2,123); // A new vector - {123,123}
    inV.insert(inV.begin(), newV.begin(), newV.end()); //adds elements from newV in inV
    printvector(inV);

    // Other Functions in vector
    int n = inV.size(); //returns size of inV vector
    inV.pop_back(); // last element of inV is removed
    printvector(newV);
    newV.clear(); // deletes all elements from vector
    cout<<newV.empty()<<endl; // boolean output on vector empty or not?

    return 0;
}