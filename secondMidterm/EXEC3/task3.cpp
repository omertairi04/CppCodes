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

    cout << "-----------------------------------------\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (arr[row][col] % 2 == 0) {
                // cout << arr[row][col] << " \n";
                int indexSum = row + col;
                swap(arr[row][col], indexSum);
            }
        }
        cout << "\n";
    }


    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }


    return 0;
}