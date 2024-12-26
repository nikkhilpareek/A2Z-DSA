#include<bits/stdc++.h>
using namespace std;

// We Will Return the Size of Array with Unique Elements, after that we can access the unique array directly with that size.
int removeDuplicatesBrute(int arr[],int n){
    set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto it: st){
        arr[index] = it;
        index++;
    }

    return index;
}

int removeDuplicatesOptimal(int arr[], int n){
    // We Will be using 2 Pointer Approach here
    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n,m;
    cout<<"Enter the number of elements in the array1: ";
    cin>>n;
    cout<<"Enter the number of elements in the array2: ";
    cin>>m;
    int arr[n];
    int arr2[m];
    cout<<"Enter the Elements of Array1: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Enter the Elements of Array2: ";
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }

    int uniqueElements = removeDuplicatesBrute(arr,n);
    cout<<"Unique Elements after Removing Duplicates by Brute Force Solution are: ";
    for(int i = 0; i<uniqueElements; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int uniqueOptimal = removeDuplicatesOptimal(arr2,m);
    cout<<"Unique Elements after Removing Duplicates by Optimal Solution are: ";
    for(int i = 0; i<uniqueOptimal; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}