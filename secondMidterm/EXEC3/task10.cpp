#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int arr[n][n];
int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            b[i][j]=arr[i][j];
        }
    }

    for (int row=0;row<n;row++) {
        for (int col=0;col<n;col++) {
            if (arr[row][col] < 0) {

    int sum=0;
                // int topIndex;
                // int bottomIndex;
                // int leftIndex;
                // int rightIndex;
                
                if (row>0) {
                    //cout << "topIndex: " << arr[row-1][col] << "\n";
                    sum = sum + arr[row-1][col];
                }
                if (row < n -1) {
                    //cout << "bottomIndex: " << arr[row+1][col] << "\n";
                    sum = sum +arr[row+1][col];
                }
                if (col > 0) {
                  //  cout << "leftIndex: " << arr[row][col-1] << "\n";
                    sum = sum +arr[row][col-1];
                }
                if (col < n - 1) {
                //    cout << "rightIndex: " << arr[row][col+1] << "\n";
                    sum = sum + arr[row][col+1];
                }
                    // cout << "sum: " << sum << "\n";
             cout<<sum<<" ";

            }
            else{
                cout<<arr[row][col]<<" ";
            }
        }
        cout<<endl;
    }




}

// 3
// 3 5 -7
// 2 -3 -2
// -3 4 7


// 3 
// 3 5 7
// 2 -3 2
// 3 4 7