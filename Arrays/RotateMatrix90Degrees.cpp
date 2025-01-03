#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > rotateMatrixBrute(vector<vector<int> > &v, int n){
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix[j][n-i-1] = v[i][j];  
        }
    }
    return matrix;
}

vector<vector<int> > rotateMatrixOptimal(vector<vector<int> > &mat, int n){
    // transpose the matrix & reverse every row.
    // diagonal elements do not change in transpose
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i =0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    return mat;
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
    int n;
    cout << "Enter Order of Square Matrix: ";
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n)); 

    cout << "Enter Elements of Matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout<<"Original Matrix is: "<<endl;
    printMatrix(matrix,n,n);
    cout<<"Matrix after Rotation by Brute Force Method is: "<<endl;
    matrix = rotateMatrixBrute(matrix,n);
    printMatrix(matrix,n,n);
    cout<<"Matrix after Rotation by Optimal Method is: "<<endl;
    matrix = rotateMatrixOptimal(matrix,n);
    printMatrix(matrix,n,n);
    return 0;
}