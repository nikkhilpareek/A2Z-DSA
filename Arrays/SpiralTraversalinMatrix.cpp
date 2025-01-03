#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int> > mat,int n,int m){
    int left = 0, right = m-1, top = 0, bottom = m-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
        for(int i = left; i<=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        for(int i = top; i<=bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i = right; i>=left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i = bottom; i>=top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

void printVector(vector<int> &v){
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

void printMatrix(vector<vector<int> > &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cout << "Enter Number of Rows: ";
    cin >> n;
    cout << "Enter Number of Columns: ";
    cin >> m;

    vector<vector<int> > matrix(n, vector<int>(m)); 

    cout << "Enter Elements of Matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout<<"Original Matrix: "<<endl;
    printMatrix(matrix,n,m);
    vector<int> ans = spiralMatrix(matrix,n,m);
    cout<<"Spiral Traversal of Matrix: "<<endl;
    printVector(ans);
    return 0;
}