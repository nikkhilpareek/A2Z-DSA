#include<bits/stdc++.h>
using namespace std;

int pascalTriangleElement(int row, int column){ 
    int n = row-1;
    int r = column-1;
    int res = 1; // it is nCr
    for(int i = 0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

vector<int> pascalTriangleRow(int row){
    vector<int> ans;
    for(int i = 1; i<=row; i++){
        int temp = pascalTriangleElement(row,i);
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int> > pascalTriangle(int N){
    vector<vector<int> > ans;
    for(int i = 1; i<=N; i++){
        ans.push_back(pascalTriangleRow(i));
    }
    return ans;
}

void printTriangle(vector<vector<int> > &pt){
    for(int i = 0; i<pt.size(); i++){
        for(int j = 0; j<pt[i].size(); j++){
            cout<<pt[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter No. of Rows to Generate";
    cin>>n;
    vector<vector<int> > pt = pascalTriangle(n);
    printTriangle(pt);
    return 0;
}