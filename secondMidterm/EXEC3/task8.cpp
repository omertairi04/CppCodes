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


    int leftFirstEl = arr[0][0];
    cout << "leftF " << leftFirstEl << "\n";
    int rightFirstEl = arr[0][n- 1];
    cout << "rightL " << rightFirstEl << "\n";
    int bottomRightEl = arr[n- 1][n-1];
    cout << "bottomRightEl " << bottomRightEl << "\n";
    int bottomLeftEl = arr[n-1][0];
    cout << "bottomLeftEl " << bottomLeftEl << "\n";

    n /= 2;
    int newArr[n][n];

    int sum = bottomRightEl + rightFirstEl + leftFirstEl + bottomLeftEl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            newArr[i][j] = sum;
            cout << newArr[i][j] << " ";
        }
        cout << "\n";
    }
}




