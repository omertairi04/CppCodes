#include <iostream>
using namespace std;

#define size 100
int n , m;
void printDiagonalElements(int matrix[size][size], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int checkIslands(int arr[size][size], int rows, int columns) {
    int count = 0;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            if (arr[i][j] == 1 && arr[i - 1][j] == 1 && arr[i][j - 1] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    int matrix[size][size]; // Assuming a maximum size of 100 for the columns
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    cout << "------------------" << endl;

    // printDiagonalElements(matrix, m , n);

   int islands = checkIslands(matrix,m, n);
   cout << islands<<endl;
    return 0;
}