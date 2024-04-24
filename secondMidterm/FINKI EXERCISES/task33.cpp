#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    float arr[n][n];

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> arr[row][col];
        }
    }

    float zDiagonalArray[100][100];

    for (int j=0;j<n;j++) {
        zDiagonalArray[0][j] = arr[0][j];
    }

    // Copy the anti-diagonal and last column
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (i + j == n - 1) {
                zDiagonalArray[i][n - 1] = arr[i][j]; // Copy to last column
                zDiagonalArray[0][99 - i] = arr[i][j]; // Copy to anti-diagonal in the first column
            }
        }
    }

    for (int j=n-1;j>=0;j--) {
        zDiagonalArray[n-1][n-1-j] = arr[n-1][j];
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << zDiagonalArray[i][j] << " ";
        }
        cout << "\n";
    }

}
