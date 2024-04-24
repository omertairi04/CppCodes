#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) {
                arr[i][j] *= -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}




