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
    
    int count=0;
    for (int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = 0;
                count++;
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
              if (arr[i+1][j-n-1] != 1) {
                arr[i+1][j-n-1] = 1;
                count++;
            }
        }
    }
  

    cout << count << "\n";

}