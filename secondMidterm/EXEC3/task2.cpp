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
            if (row > col && row + col == n - 1) {
                // Change the sign of the element
                arr[row][col] *= -1;
            }
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }

    return 0;
}
