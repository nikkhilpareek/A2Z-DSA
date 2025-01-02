#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int> > &arr, int i) {
    for (int j = 0; j < arr[0].size(); j++) { 
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void markColumn(vector<vector<int> > &arr, int j) {
    for (int i = 0; i < arr.size(); i++) { 
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void setMatrixZeroesBrute(vector<vector<int> > &arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, i);
                markColumn(arr, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
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
    setMatrixZeroesBrute(matrix, n, m); 
    cout << "\nMatrix after setting zeroes:" << endl;
    printMatrix(matrix, n, m); 
    return 0;
}
