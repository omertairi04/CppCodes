#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    
    for (int i=0;i<n -1 ;i+=2) {
        int nums = arr[i] * 10 + arr[i+1];
        if (nums % nums == 0) {
            cout << "number " << nums << " is a prime number" << "\n";
        } else {
            cout << "number " << nums << " is not a prime number" << "\n";
        }
    }

    if (n % 2 != 0) {
        if (arr[n-1 ] % arr[n - 1] == 0) {
            cout << "number " << arr[n-1] << " is a prime number" << "\n";

        } else {
            cout << "number " << arr[n-1] << " is not a prime number"<< "\n";

        }
        cout << "\n";
    }
}