#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int arr[m][n]; // Fixed size arrays should use constants or dynamic memory allocation.

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int midRowStart = m / 2 - 1;  // Start index of the first of the two middle rows
    int midRowEnd = m / 2;        // End index of the second of the two middle rows

    int midColStart = n / 2 - 1;  // Start index of the first of the two middle columns
    int midColEnd = n / 2;        // End index of the second of the two middle columns

    
    // Print the middle rows
    for (int i = midRowStart; i <= midRowEnd; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // Print the elements of the two middle columns
    for (int i = 0; i < m; i++) {
        for (int j = midColStart; j <= midColEnd; j++) {
            if (j == midColStart || j == midColEnd) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }


}