#include <iostream>
#include <algorithm>
using namespace std;

void transformArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i + 1]) {
            arr[i] *= 2;
            arr[i + 1] = 0;
            i++; // Skip the next element as it's already merged
        }
    }
}

void sortZeroToEnd(int arr[], int n) {
    int nonZeroIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
}
}

int main() {
    int m;
    cin >> m;

    int arr[m];

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    transformArray(arr , m - 1);
    sortZeroToEnd(arr , m );
    
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
