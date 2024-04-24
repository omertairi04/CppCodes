#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<n;i++) {
        if (arr[i] % 2 == 0) {
            arr[i] += 3;
        }
        if (arr[i] % 2 == 1 && arr[i] % 5 == 0) {
            arr[i] -= 2;
        }
    }


    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

}



