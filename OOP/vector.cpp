#include <iostream>

struct Vector {
  float x, y, z;

  float scalarProduct(Vector v) { return x * v.x + y * v.y + z * v.z; }

  Vector vProduct(Vector v) {
    Vector result;

    result.x = y * v.z - z * v.y;
    result.y = z * v.x - x * v.z;
    result.z = x * v.y - y * v.x;

    return result;
  }

  void print() { std::cout << "[" << x << ", " << y << ", " << z << "]\n"; }
};

int main() {

  Vector v1 = {2, 4, 6};
  Vector v2 = {3, 5, 9};

  std::cout << "SCALAR PRODUCT\n";
  std::cout << "v1 * v2 = " << v1.scalarProduct(v2) << "\n";

  std::cout << "VECTOR PRODUCT\n";
  v1.vProduct(v2).print();
  return 0;
}
