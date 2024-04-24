#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;

class Array {
  int *integers;
  int capacity;
  int sizeTaken;

  void copy(const Array &a) {
    sizeTaken = a.sizeTaken;
    capacity = a.capacity;
    integers = new int[capacity];
    for (int i = 0; i < sizeTaken; i++) {
      integers[i] = a.integers[i];
    }
  }

public:
  Array(){};

  Array(const Array &a) { copy(a); }

  Array(const int capacity = 5) {
    integers = new int[capacity];
    sizeTaken = 0;
    this->capacity = capacity;
  }

  Array &operator+=(int n) {
    if (sizeTaken >= capacity) {
      int *temp = new int[2 * capacity];
      for (int i = 0; i < sizeTaken; i++) {
        temp[i] = integers[i];
      }
      delete[] integers;
      integers = temp;
      capacity = capacity * 2;
    }
    integers[sizeTaken] = n;
    sizeTaken++;
    return *this;
  }

  Array &operator-=(int n) {
    int newSize = 0;
    for (int i = 0, j = 0; i < sizeTaken; ++i) {
      if (integers[i] != n) {
        integers[j++] = integers[i];
        newSize++;
      }
      sizeTaken = newSize;
      return *this;
    }
  }

  friend ostream &operator<<(ostream &out, Array &a) {
    for (int i = 0; i < a.sizeTaken; i++) {
      out << a.integers[i] << " ";
    }
    return out;
  }

  int &operator[](int index) {
    int pom = -1;
    if (index >= 0 && index < sizeTaken) {
      return integers[index];
    } else {
      return pom;
    }
  }

  bool operator==(Array &a) {
    if (this->sizeTaken != a.sizeTaken)
      return false;
    for (int i = 0; i < sizeTaken; i++) {
      if (integers[i] != a.integers[i])
        return false;
    }
    return true;
  }
};

int main() {}