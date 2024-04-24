#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int arr[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }

    int dir = 0, top = 0, down = rows - 1, left = 0, right = columns - 1;

    while (top <= down && left <= right) {

        if (dir == 0) {
            for (int i = left; i <= right; i++) {
                cout << arr[top][i] << " ";
            }
            top++;
        } else if (dir == 1) {
            for (int i = top; i <= down; i++) {
                cout << arr[i][right] << " ";
            }
            right--;
        } else if (dir == 2) {
            for (int i = right; i >= left; i--) {
                cout << arr[down][i] << " ";
            }
            down--;
        } else if (dir == 3) {
            for (int i = down; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
}
