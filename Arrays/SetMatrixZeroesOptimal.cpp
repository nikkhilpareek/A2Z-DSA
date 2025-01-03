#include<bits/stdc++.h>
using namespace std;

void setMatrixZeroesOptimal(vector<vector<int> > &v, int n, int m){
    int col0 = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == 0){
                v[i][0] = 0;
                if(j!=0) v[0][j] = 0;
                else col0 = 0;
            }
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(v[i][j] != 0){
                if(v[0][j] == 0 || v[i][0] == 0){
                    v[i][j] = 0;
                }
            }
        }
    }
    if(v[0][0] == 0){
        for(int j = 0; j<m; j++) v[0][j] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i<n; i++){
            v[i][0] = 0;
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
    setMatrixZeroesOptimal(matrix, n, m); 
    cout << "\nMatrix after setting zeroes:" << endl;
    printMatrix(matrix, n, m); 
    return 0;
}
