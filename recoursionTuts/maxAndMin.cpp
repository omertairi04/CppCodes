#include <iostream>
using namespace std;

int findMax(int arr[] , int start , int end) {    
    if (start == end) return arr[start];

    int mid = (start + end) / 2;
    int maxOfLeftSide = findMax(arr, start , mid);
    int maxOfRightSide = findMax(arr, mid + 1, end);

    if (maxOfLeftSide > maxOfRightSide ) return maxOfLeftSide;
    else {
        return maxOfRightSide;
    }

}

int findMin (int arr[] , int start , int end) {
    if (start == end) return arr[start];

    int mid = (start + end) / 2;
    int minOfLeftSide = findMin(arr, start, mid);
    int minOfRightSide = findMin(arr, mid + 1, end);

    if (minOfLeftSide < minOfRightSide) return minOfLeftSide;
    else return minOfRightSide;
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int max = findMax(arr, 0 , n-1);
    int min = findMin(arr, 0,n-1);

    cout << "-------------------------\n";
    cout << max << "\n";
    cout << "-------------------------\n";
    cout << min << "\n";
}


