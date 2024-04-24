#include <iostream>

/*
Basically the same as with Capacity but a few extra steps
after entering all the data into the array, the element to insert
and the positionToEnter check if position we want to insert the element is
bigger than the size of the array, if it isnt then just call the function
but if it is then create a new array with a bigger size, then copy the elements
from the old array and then call the function
*/

void insertElement(int arr[], int &size, int element, int position) {
  for (int i = size - 1; i >= position; i--) {
    arr[i + 1] = arr[i];
  }
  arr[position] = element;
  size++;
}

int main() {
  int size;
  std::cin >> size;

  int arr[size];

  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  int elementToEnter;
  std::cin >> elementToEnter;

  int positionToEnter;
  std::cin >> positionToEnter;

  if (positionToEnter < size) {
    insertElement(arr, size, elementToEnter, positionToEnter);
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
  } else {
    int array2[size + 1];
    for (int i = 0; i < size; i++) {
      array2[i] = arr[i];
    }

    insertElement(array2, size, elementToEnter, positionToEnter);
    for (int i = 0; i < size; i++) {
      std::cout << array2[i] << " ";
    }
  }
}
