#include <iostream>
using namespace std;

/*
enter element arrays + size(obv)
enter element and position

call the function that takes
arr[] - the array in which you want to add the element
&size - size of the array (we have a reference because we will increase it's
size by one) element - the element we want to insert position - the position we
want to add the said element

we go from:
i=size - 1 ; as long as i>=position;decrease i by one
then move the array at i for one position to the right to make place for the
element we want to insert
add the element at desired position in the array
increase size after puttin the element
*/

void insertElement(int arr[], int &size, int element, int position) {
  if (position < size - 1) {
    for (int i = size - 1; i >= position; i--) {
      arr[i + 1] = arr[i];
    }

    arr[position] = element;
    size++;
  }
}

int main() {
  int size;
  cin >> size;

  int arr[size];

  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  int elementToEnter;
  cin >> elementToEnter;

  int positionToEnter;
  cin >> positionToEnter;

  insertElement(arr, size, elementToEnter, positionToEnter);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}
