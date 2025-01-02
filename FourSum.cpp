#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &v, int target){
    int n = v.size();
    vector<vector<int> > ans;
    sort(v.begin(), v.end());
    for(int i = 0; i<n; i++){
        if(i>0 && v[i] == v[i-1]){
            continue;
        }
        for(int j = i+1; j<n; j++){
            if(j!=(i+1) && v[j] == v[j-1]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = v[i]+v[j]+v[k]+v[l];
                if(sum == target){
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    temp.push_back(v[k]);
                    temp.push_back(v[l]);
                    ans.push_back(temp);
                    k++; 
                    l--;
                    while(k<l && v[k] == v[k-1]){
                        k++;
                    }
                    while(k<l && v[l] == v[l+1]){
                        l--;
                    }

                }else if(sum<target){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }
    return ans;
}

void printAns(vector<vector<int> > &v){
    int n = v.size();
    for(int i = 0; i<n; i++){
        cout<<"{ ";
        for(int j = 0; j<4; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
}

int main(){
    int n,target;
    cout<<"Enter Target Sum: ";
    cin>>target;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<vector<int> > ans = fourSum(v,target);
    printAns(ans);
    return 0;
}