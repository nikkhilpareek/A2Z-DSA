#include<bits/stdc++.h>
using namespace std;

// if i<j & a[i]>a[j], return count of pairs

int countInversionBrute(int v[], int n){
    int cnt = 0;
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]>v[j]) cnt++;
        }
    }
    return cnt;
}

// in optimal solution we use Merge Sort and count whenever right element is smaller
int merge(int arr[], int low ,int mid, int high){
    std::vector<int> temp;
    int cnt = 0;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++ ){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mergeSort(int arr[], int l, int h) {
    int cnt = 0;
    if(l>=h){
        return cnt;
    }
    int mid = (l+h)/2;
    cnt += mergeSort(arr, l, mid);
    cnt += mergeSort(arr,mid+1, h);
    cnt += merge(arr,l,mid,h);
    return cnt;
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
    cout<<"Inversion Count by Brute Force: "<<countInversionBrute(arr,n)<<endl;
    cout<<"Inversion Count by Optimal Force: "<<mergeSort(arr,0,n)<<endl;
    return 0;
}