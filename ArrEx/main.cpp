#include <iostream>

using namespace std;

int main() {
	int arr[100];
	int n;
	int i=0;
	while (cin >> n) {
		if (n == -1) {
			break;
		}
		arr[i] = n;
		i++;
	}

	for (int j=0;j<i;j++) {
		cout << arr[i] << " ";
	}
}