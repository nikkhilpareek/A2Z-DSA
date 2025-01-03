#include<bits/stdc++.h>
using namespace std;

vector<int> missingRepeatingBrute(vector<int> &v){
    int n = v.size();
    vector<int> ans;
    int repeating = -1, missing = -1;
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(v[j] == i){
                cnt++;
            }
        }
        if(cnt==2) repeating = i;
        else if(cnt == 0) missing = i;
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

vector<int> missingRepeatingBetter(vector<int> &v){
    vector<int> hash(v.size()+1,0);
    vector<int> ans;
    for(int i = 0; i<v.size(); i++){
        hash[v[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i = 1; i<=v.size(); i++){
        if(hash[i]==2) repeating = i;
        else if(hash[i] == 0) missing = i;
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

vector<int> missingRepeatingOptimal(vector<int> &v){
    // This is using SUM
    // We Will generate two equations
    // sum of array - actual sum of n nos and sum of square of array element - actual sum of square of n nos. 
    // x -> Repeating Number, y -> Missing Number
    int n = v.size();
    vector<int> ans;
    int S = 0; // Sum of Array Elements
    int S2 = 0; // Sum of Square of Array Elements
    int Sn = (n*(n+1))/2; // Sum of First N Natural Numbers
    int S2n = (n*(n+1)*(2*n+1))/6; // Sum of Squares of First N Natural Numbers
    for(int i = 0; i<n; i++){
        S+=v[i];
        S2+=v[i]*v[i];
    }
    int val1 = S-Sn; // x-y
    int val2 = S2-S2n;
    val2 = val2/val1; // (x+y)
    int x = (val1+val2)/2;
    int y = x-val1;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

vector<int> repeatingMissingOptimalxor(vector<int> &v) {
    int n = v.size();
    vector<int> ans;
    int xr = 0;

    // Compute XOR of all elements in the array and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xr = xr ^ v[i];
        xr = xr ^ (i + 1);
    }

    // Find the rightmost set bit in `xr`
    int number = xr & ~(xr - 1);

    // Initialize buckets
    int zero = 0, one = 0;

    // Separate numbers into two groups based on the set bit
    for (int i = 0; i < n; i++) {
        if ((v[i] & number) != 0) {
            one = one ^ v[i];
        } else {
            zero = zero ^ v[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0) {
            one = one ^ i;
        } else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == zero) cnt++;
    }

    if (cnt == 2) {
        ans.push_back(zero); // Repeating number
        ans.push_back(one);  // Missing number
    } else {
        ans.push_back(one);  // Repeating number
        ans.push_back(zero); // Missing number
    }

    return ans;
}


void printVector(vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    vector<int> arr;
    cout<<"\nEnter Array Elements";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> ansBrute = missingRepeatingBrute(arr);
    cout<<"By Brute Force: ";
    printVector(ansBrute);
    vector<int> ansBetter = missingRepeatingBetter(arr);
    printVector(ansBetter);
    vector<int> ansOptimalsum = missingRepeatingOptimal(arr);
    printVector(ansOptimalsum);
    vector<int> ansOptimalxor = repeatingMissingOptimalxor(arr);
    printVector(ansOptimalxor);
    return 0;
}