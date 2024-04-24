#include <cctype>
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n][n];


    int arrB[100][100];

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            arrB[i][j] = arr[i][j];
        }
    }

    int countOnes = 0;
    bool threeInARow = false;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (arrB[i][j] == 0) {
                if (arrB[i-1][j-1] == 1) {
                    countOnes++;
                    cout << "arrB[i-1][j-1]" << arrB[i-1][j-1] << "\n";
                } else if (arrB[i][j+1] == 1) {
                    countOnes++;
                    cout << "arrB[i][j+1]" << arrB[i][j+1] << "\n";
                } else if (arrB[i][j-1] == 1) {
                    countOnes++;
                    cout << "arrB[i][j-1]" << arrB[i][j-1] << "\n";
                } else if (arrB[i+1][j] == 1) {
                    countOnes++;
                    cout << "arrB[i+1][j]" << arrB[i+1][j] << "\n";
                }
            }
            
        }
        // cout << " \n";
    }

    if (countOnes >= 3) {
        threeInARow = true;
    }
    cout << "countOnes" << countOnes << " \n";
    if (threeInARow) cout << true << " \n";


}



/*
5
1 0 0 1 0
1 1 0 1 0
1 1 1 1 1
0 1 0 0 1
1 0 1 1 0
*/
