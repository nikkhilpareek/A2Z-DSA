#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > mergeIntervalsBrute(vector<vector<int> >&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int> > ans;
    for(int i=0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j = i+1; j<n; j++){
            if(arr[j][0]<=end){
                end = max(end,arr[j][1]);
            }else{
                break;
            }
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int> > mergeIntervalsOptimal(vector<vector<int> >&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int> > ans;
    for(int i = 0; i<n; i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

void printMatrix(vector<vector<int> > &matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter Number of Intervals: ";
    cin >> n;

    vector<vector<int> > v(n, vector<int>(2)); 

    cout << "Enter Elements of Matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int> > ans  = mergeIntervalsBrute(v);
    printMatrix(ans,ans.size());
    return 0;
}