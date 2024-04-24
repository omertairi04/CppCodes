#include <iostream>
using namespace std;

int main() {
    int m, n, row, col;
    cin >> m >> n;

    int arr[100][100]; // Fixed size arrays should use constants or dynamic memory allocation.

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> row >> col;

    if (arr[row][col] == 0) {
        arr[row][col] = 1;

        // Update upwards
        for (int i = row - 1; i >= 0 && arr[i][col] != 1; i--) {
            arr[i][col] = 1;
        }

        // Update downwards
        for (int i = row + 1; i < m && arr[i][col] != 1; i++) {
            arr[i][col] = 1;
        }

        // Update leftwards
        for (int j = col - 1; j >= 0 && arr[row][j] != 1; j--) {
            arr[row][j] = 1;
        }

        // Update rightwards
        for (int j = col + 1; j < n && arr[row][j] != 1; j++) {
            arr[row][j] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}