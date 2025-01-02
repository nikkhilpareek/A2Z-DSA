#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSumBrute(vector<int> &v){
    int n = v.size();
    set<vector<int> > st;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(v[i]+v[j]+v[k] == 0){
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    temp.push_back(v[k]);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int> > ans(st.begin(), st.end());
    return ans;
}

vector<vector<int> > threeSumBetter(vector<int> &v){
    // arr[k] = -(arr[i] + arr[j])
    set<vector<int> > st; 
    int n = v.size();
    for(int i  = 0; i<n; i++){
        set<int> hashset;
        for(int j = i+1; j<n; j++){
            int third = -1*(v[i]+v[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp;
                temp.push_back(v[i]);
                temp.push_back(v[j]);
                temp.push_back(third);
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]);
        }
    }
    vector<vector<int> > ans(st.begin(),st.end());
    return ans;
}

vector<vector<int> > threeSumOptimal(vector<int> v){
    vector<vector<int> > ans;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i = 0; i<n; i++){
        if(i>0 && v[i] == v[i-1]) continue;
        int j = i+1; int k = n-1;
        while(j<k){
            int sum = v[i]+v[j]+v[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int> temp;
                temp.push_back(v[i]);
                temp.push_back(v[j]);
                temp.push_back(v[k]);
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && v[j] == v[j-1]){
                    j++;
                }
                while(j<k && v[k] == v[k+1]){
                    k--;
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
        for(int j = 0; j<3; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<vector<int> > ans = threeSumBrute(v);
    printAns(ans);
    ans = threeSumBetter(v);
    printAns(ans);
    ans = threeSumOptimal(v);
    printAns(ans);
    return 0;
}