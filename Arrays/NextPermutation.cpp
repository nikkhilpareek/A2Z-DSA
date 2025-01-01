#include<bits/stdc++.h>
using namespace std;

// Brute force is useless here as it will go in O(n!) time complexity which is very very high

vector<int> nextPermutationSTL(vector<int> a){
    // Using C++ STL to Find Next Permutation Directly
    next_permutation(a.begin(), a.end());
    return a;
}

vector<int> nextPermutationOptimal(vector<int> a){
    // Step 1: Find Longer Prefix Match by a[i]<a[i+1], This will help us in finding our breakpoint a[i]
    // Step 2: Find the element >a[i] but also the smallest one & swap it with a[i].
    // Step 3: place elements after breakpoint in sorted order.
    int n = a.size();
    int index = -1;
    for(int i = n-2; i>=0; i--){
        if(a[i]<a[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(a.begin(), a.end());
        return a;
    }

    for(int i = n-1; i>=index; i--){
        if(a[i]>a[index]){
            swap(a[i], a[index]);
            break;
        }
    }
    reverse(a.begin()+index+1, a.end());
    return a;
}

void printVector(vector<int> arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Elements of Array: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Original Array: ";
    printVector(arr,n);
    cout<<"Next Permutation of array by STL Method: ";
    printVector(nextPermutationSTL(arr),n);
    cout<<endl;
    cout<<"2nd Next Permutation of array by Optimal Method: ";
    printVector(nextPermutationOptimal(arr),n);
    cout<<endl;
    return 0;
}