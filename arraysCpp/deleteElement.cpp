#include <iostream>

/*
insert data into the array then get the position of the index to be deleted
the make a function to delete with the array, size of the array and the
position of the index to delete.
Then in a loop from i = position till i < size - 1 ; i++ -> arr[i] = arr[i + 1]
then just decrease size
*/

void deleteElement(int arr[], int &size, int position) {
  for (int i = position; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
}

int main() {
  int size;
  std::cin >> size;

  int arr[size];

  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  int positionToDelete;
  std::cin >> positionToDelete;

  deleteElement(arr, size, positionToDelete);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}
