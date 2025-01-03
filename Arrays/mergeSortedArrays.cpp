#include<bits/stdc++.h>
using namespace std;

// Brute Force - Create a Thhird array and add elements from given arrays in sorted order.

// Better Solution - if arr2[j] < arr1[i] then swap, else stop.
void mergeArraysBetter(long long arr1[], long long arr2[], int n, int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}

void mergeSortedOptimal(long long arr1[], long long arr2[], int n, int m){
    //Using Gap Method - derived from Shell Sort
    // gap = ceil((n+m)/2);
    int len = n+m;
    int gap = (len/2)+(len%2);
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right<len){
            // arr1 & arr2
            if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            // arr2 & arr2
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            // arr1 & arr1
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = gap/2 + gap%2;
    }
}

int main(){
    int n,m;
    cout<<"Enter Length of Array 1 And Array 2: ";
    cin>>n>>m;
    long long arr1[n], arr2[m];
    cout<<"Enter Elements of Array 1: ";
    for(int i = 0; i<n; i++){
        cin>>arr1[i];
    }
    cout<<"Enter Elements of Array 2: ";
    for(int i = 0; i<m; i++){
        cin>>arr2[i];
    }
    mergeSortedOptimal(arr1,arr2,n,m);
    // Printing Merged Array:
    cout<<"Merged Array is: ";
    for(int i = 0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    for(int i = 0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}