#include <iostream>
using namespace std;


int main() {
    int row , col;
    cin >> row >> col;
    int arr[row][col];
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for (int i=0;i<col ;i++) {
        for (int j=0;j<row-2;j++) {
            
            if (arr[j][i] == 1 && arr[j+1][i] == 1 && arr[j+2][i] == 1) {
                count++;
                break;
            }
        }
    }
    for (int i=0;i<row;i++) {
        for (int j=0;j<col - 2;j++) {
            
            if (arr[i][j] == 1 && arr[i][j+1] == 1 && arr[i][j+2] == 1) {
                count++;
                break;
            }
        }
    }
    cout << count << " \n";
}
