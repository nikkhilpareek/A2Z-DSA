#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionArrayBrute(vector<int> a, int n, vector<int> b, int m){
    vector<int> ans;
    vector<int> vis(m,0);
    for(int i =0; i<n; i++){
        for(int j = 0;j<m;j++){
            if(a[i]==b[j] && vis[j]==0){
                ans.push_back(b[j]);
                vis[j] = 1;
            }
            else if(b[j]>a[i]){
                break;
            }
        }
    }
    return ans;
}

vector<int> intersectionArrayOptimal(vector<int> a, int n, vector<int> b, int m){
    int i = 0, j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i]<b[j]){
            i++;
        }else if(b[j]<a[i]){
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

void printVector(vector<int> v){
    int n = v.size();
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cout<<"Enter Size of First Array: ";
    cin>>n;
    cout<<"Enter Size of Second Array: ";
    cin>>m;
    vector<int> a,b;
    
    cout<<"Enter Elements of First Array: ";
    for(int i =0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    cout<<"Enter Elements of Second Array: ";
    for(int i =0;i<m;i++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }

    vector<int> ans = intersectionArrayBrute(a,n,b,m);
    vector<int> ans2 = intersectionArrayOptimal(a,n,b,m);
    printVector(ans);
    printVector(ans2);
    return 0;
}