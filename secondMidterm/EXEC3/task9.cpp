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
        int min = 1e9;
        int max = 0;
        for (int j = 0; j < n; j++) { // Start from index 1, assuming 0 is already considered
            if (arr[i][j] < min) {
                min = arr[i][j];
                // min = 0;
            }
            if (arr[i][j] > max) {
                max = arr[i][j];
                // max = 1;
            } 
        }
        for(int j=0;j<n;j++){
            if (min == arr[i][j]) {
                arr[i][j] = 0;
            }
            if (max == arr[i][j]) {
                arr[i][j] = 1;
            }
        }
        // cout << "Row " << i << ": Min = " << min << ", Max = " << max << endl;
    }

    // main diagonal
    int min = 1e9;
    int max = 0;
    for (int i=0;i<n;i++) {
        if (arr[i][i] < min) {
            min = arr[i][i];
        }
        if (arr[i][i] > max) {
            max = arr[i][i];
        }
    }

    for (int i=0;i<n;i++) {
        if (min == arr[i][i]) {
            arr[i][i] = 0;
        }
        if (max == arr[i][i]) {
            arr[i][i] = 1;
        }
    }



    // anti diagonal
    min=1e9;
    max=0;

    for (int i=0;i<n;i++) {
        if (arr[i][n-i-1] < min) {
            min = arr[i][n-i-1];
        }
        if (arr[i][n-i-1] > max) {
            max = arr[i][n-i-1];
        }
    }

    for (int i=0;i<n;i++) {
        if (min == arr[i][n-i-1]) {
            arr[i][n-i-1] = 0;
        }
        if (max == arr[i][n-i-1]) {
            arr[i][n-i-1] = 1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}


// 3
// 4 9 2
// 7 5 3
// 6 1 8