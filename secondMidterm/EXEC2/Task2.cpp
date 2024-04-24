#include <iostream>
using namespace std;


int main() {
    int n;

    cin >> n;

    int arr1[n];

    for (int i=0;i<n;i++) {
        cin >> arr1[i];
    }

    // subarray
    int startIndex = 0;
    int length = n;
    int endIndex = startIndex + length;
    if (endIndex > sizeof(arr1) / sizeof(arr1[0])) {
        endIndex = sizeof(arr1) / sizeof(arr1[0]);
    }

    int subArray[length];
    for (int i=startIndex , j=0;i<endIndex;++i,++j) {
        subArray[j] = arr1[i];
    }

    int max=0;
    for (int i = 0; i < length; ++i) {
        std::cout << subArray[i] << " ";
        max += subArray[i];
    }
    cout << "\n";

    cout << "max " << max << "\n";


}