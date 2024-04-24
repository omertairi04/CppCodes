#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    int arr[n][n]; // Fixed size arrays should use constants or dynamic memory allocation.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // cout << " -------------------------------\n";
    int maxMainDiagonal=arr[0][0], minAntiDiagonal = arr[n-1][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            // // find main diagonal
            // cout << "arr[j - 1][j + 1] " << arr[j-1][j + 1]  << "\n";
            // cout << "maxMainDiagonal " << maxMainDiagonal  << "\n";

            
            if (arr[j-1][j+1] > maxMainDiagonal) {
                maxMainDiagonal = arr[j-1][j+1];
            }
        }
    }

    for (int j = 1; j < n-1; j++) {
            // // find main diagonal
            // cout << "arr[j - 1][j + 1] " << arr[j-1][j + 1]  << "\n";
            // cout << "maxMainDiagonal " << maxMainDiagonal  << "\n";

            
            if (arr[j-1][j+1]) {
                arr[j-1][j+1] = maxMainDiagonal ;
            }
    }

    // cout << "maxMainDiagonal " << maxMainDiagonal  << "\n";


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // cout << "maxMainDiagonal" << maxMainDiagonal << "\n";
    
    // cout << " -------------------------------\n";

    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j < n -1; j++) {
    //         // find main diagonal


    //         // cout << "arr[i][j + 1]" << arr[i][j + 1]  << "\n";
    //         // cout << "minAntiDiagonal " << arr[i][j + 1]  << "\n";
            
    //         if (arr[i][j + 1] < minAntiDiagonal) {
    //             minAntiDiagonal = arr[i][j+1];
    //         }
    //     }
    // }
    // cout << "minAntiDiagonal" << minAntiDiagonal << "\n";

}

/*

5 5
200 100 4 5 9
3 200 50 49 3
70 70 200 20 3
70 70 70 200 2
70 70 70 70 200

*/
