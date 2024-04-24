#include <iostream>
using namespace std;

int main() {

    int n, rowSum , colSum, mainDiagonal , antiDiagonal;
    bool isMagic = true;
    cin >> n;

    int arr[n][n];

    for (int row=0;row<n;row++) {
        for (int col=0;col<n;col++) {
            cin >> arr[row][col];
        }   
    }

    // MAIN DIAGONAL
    for (int row=0;row<n;row++) {
        mainDiagonal += arr[row][row];
    }

    // ANTI DIAGONAL
    for (int row=0;row<n;row++) {
        antiDiagonal += arr[row][n - 1 - row];
    }

    // CHECK IF DIAGONAL SUMS ARE EQUAL
    if (mainDiagonal != antiDiagonal) {
        isMagic = false;
    }

    // PRINT AND MODIFY IF IT IS MAGIC
    if (isMagic) {
        cout << "True \n";

    // MODIFY MAIN DIAGONAL
    for (int row=0;row<n;row++) {
        mainDiagonal += arr[row][row];
    }

    }

}

