#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n];

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> arr[row][col];
        }
    }

    int columnSum[100] = {0};
    for (int col = 0; col < n; col++) {
        for (int row = 0;row < n;row++) {
            columnSum[col] += arr[row][col];
        }
    }

    int maxSum = columnSum[0];
    int maxColIndex = 0;
    for (int col = 1;col <n;col++) {
        if (columnSum[col] > maxSum) {
            maxSum = columnSum[col];
            maxColIndex = col;
        }
    }

    for (int row=0;row<n;row++) {
        arr[row][maxColIndex] += maxSum;
    }

    cout << "Updated matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}






