#include <iostream>
using namespace std;

int main () {
    int n;

    cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0;i < n;i++) {
        for (int j=0;j<n;j++) {
            if (arr[i][j] % 2 == 0) {
                arr[i][j] = i + j;
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }
}
