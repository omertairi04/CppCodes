#include <iostream>
using namespace std;

int findSum(int array[], int size) {
    if (size <= 0) return 0;
    return findSum(array, size - 1) + array[size-1];
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findSum(arr , size);

}