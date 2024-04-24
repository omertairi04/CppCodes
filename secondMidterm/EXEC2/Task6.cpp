#include <iostream>
using namespace std;

int main() {
    int n , k;

    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cin >> k;

    swap(arr[k] , arr[k - 1]);


    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

}




