#include <iostream>
using namespace std;

int main () {
    int row , column;

    cin >> row >> column;

    int arr[row][column];
 

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<row - 1; i++) {
        for (int j = 1; j < column; j++) {
            cout << arr[0][j] << " " << arr[1][j - 1] << "\n";
        }
    }
    cout << arr[row-1][column-1] << "\n";
}

