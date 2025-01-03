#include<bits/stdc++.h>
using namespace std;

void setMatrixZeroesBetter(vector<vector<int> > &v, int n, int m){
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] || col[j]){
                v[i][j] = 0;
            }
        }
    }
}
void printMatrix(vector<vector<int> > &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
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

    printMatrix(matrix, n, m);
    setMatrixZeroesBetter(matrix, n, m); 
    cout << "\nMatrix after setting zeroes:" << endl;
    printMatrix(matrix, n, m); 
    return 0;
}
