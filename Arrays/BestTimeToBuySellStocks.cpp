#include<bits/stdc++.h>
using namespace std;

int maxProfitOptimal(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for(int i = 0; i<n; i++){
        int diff = prices[i]-mini;
        maxProfit = max(maxProfit,diff);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
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
    cout<<"Maximum Possible Profit is: "<<maxProfitOptimal(arr)<<endl;
    return 0;
}