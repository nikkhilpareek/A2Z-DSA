#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int i, int n) {
    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter Array Elements";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    insertion_sort(arr,0,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}