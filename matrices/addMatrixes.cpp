#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr1[n][n],arr2[n][n];

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr1[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr2[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << "arr1" << arr1[i][j] << " \n";
            
            cout << "arr2" << arr2[i][j] << " ";
        }
        cout << "\n";
    }

}