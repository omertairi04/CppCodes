#include <iostream>
using namespace std;


void bubbleSort(int array[] , int size) {

    for (int i=1; i<size;i++) {
        for (int j=0; j<size - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j] , array[j+1]);
            }
        }
    }
}

int binarySearch(int array[] , int size , int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == target) return mid;
        
        else if (array[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n , target;
    cout << "enter n: \n";
    cin >> n;
    
    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "enter target: \n";
    cin >> target;

    bubbleSort(arr,n);

    cout << "Sorted Array! \n";
    for (int i=0;i<n;i++) {
        cout << arr[i] << " \n";
    }

    cout << "\n";
    int getTarget = binarySearch(arr, n,target);
    cout << getTarget << "\n";

}
