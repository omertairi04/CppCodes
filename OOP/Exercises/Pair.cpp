#include <cstring>
#include <iostream>
using namespace std;

class Pair {
  char *key;
  int value;

  void copy(const Pair &p) {
    key = new char[strlen(p.key) + 1];
    strcpy(key, p.key);
    value = p.value;
  }

public:
  Pair() : key(nullptr), value(0) {}

  Pair(const Pair &p) { copy(p); }

  Pair(const char *key, int val) {
    this->key = new char[strlen(key) + 1];
    strcpy(this->key, key);
    value = val;
  }
  // prefix --
  Pair &operator--() {
    value--;
    return *this;
  }
  // postfix--
  Pair operator--(int) {
    Pair ret(*this); // Make a copy of the current object
    value--;         // Decrement the value of the current object
    return ret;      // Return the copy
  }

  friend ostream &operator<<(ostream &out, const Pair &p) {
    out << "[" << p.key << "] -> " << p.value << endl;
    return out;
  }

  Pair &operator*(const Pair &r) {
    if (strlen(this->key) < strlen(r.key)) {
      delete[] this->key;
      for (int i = 0; i < strlen(r.key); i++) {
        this->key[i] = r.key[i];
      }
    } else if (strlen(this->key) == strlen(r.key)) {
      delete[] this->key;
      for (int i = 0; i < strlen(r.key); i++) {
        this->key[i] = r.key[i];
      }
    }
    value = value * r.value;
    return *this;
  }

  int getValue() { return value; }

  ~Pair() { delete[] key; }
};

class Collection {
  Pair *pairs;
  int capacity;
  int pairsInArr;

  void copy(const Collection &c) {
    capacity = c.capacity;
    pairsInArr = c.pairsInArr;
    pairs = new Pair[capacity];
    for (int i = 0; i < pairsInArr; i++) {
      pairs[i] = c.pairs[i];
    }
  }

public:
  Collection() {}

  Collection(Collection &c) { copy(c); }

  Collection(Pair *p) : capacity(1), pairsInArr(1) { pairs = p; }

  Collection &operator+=(const Pair &p) {
    if (pairsInArr < capacity) {
      pairs[pairsInArr++] = p;
    }
    return *this;
  }

  friend ostream &operator<<(ostream &out, Collection &c) {
    out << c.pairsInArr << endl;

    for (int i = 0; i < c.pairsInArr; i++) {
      out << c.pairs << endl;
    }
    return out;
  }

  bool operator<(Collection &c) {
    int thisProduct = 0;
    int otherProduct = 0;

    for (int i = 0; i < pairsInArr; i++) {
      thisProduct += pairs[i].getValue();
    }

    for (int i = 0; i < c.pairsInArr; i++) {
      thisProduct += c.pairs[i].getValue();
    }

    return thisProduct > otherProduct;
  }

  int greater(int value) {
    for (int i = 0; i < pairsInArr; i++) {
      if (pairs[i].getValue() > value) {
        return pairs[i].getValue();
      }
    }
  }

  ~Collection() { delete[] pairs; }
};

void read(char *k, int *v) {
  cin >> k;
  cin >> *v;
}
int main() {
  char key[50];
  int value;
  cout << "----- class Pair -----" << endl;
  read(key, &value);
  cout << "----- constructor -----" << endl;
  Pair p1(key, value);
  read(key, &value);
  Pair p2(key, value);
  Pair p3(p1);
  cout << "----- operator << -----" << endl;
  cout << p1;
  cout << p2;
  cout << "----- operator --(int) -----" << endl;
  cout << p1--;
  cout << p1;
  cout << "----- operator -- -----" << endl;
  cout << --p2;
  cout << "----- operator * -----" << endl;
  Pair p = p1 * p2;
  cout << "----- operator = -----" << endl;
  p3 = p;
  cout << p3;

  cout << "----- class Collection -----" << endl;
  cout << "----- constructor -----" << endl;
  Collection k;
  cout << "----- operator += -----" << endl;
  k += p1;
  k += p2;
  k += p3;
  cout << "----- operator << -----" << endl;
  cout << k;
  cout << "----- copy constructor -----" << endl;
  Collection k2(k);
  cout << "----- operator < -----" << endl;
  if (k < k2) {
    cout << "k < k2" << endl;
  } else {
    cout << "k >= k2" << endl;
  }
  k2 += p1;
  if (k < k2) {
    cout << "k < k2" << endl;
  } else {
    cout << "k >= k2" << endl;
  }
  cout << "----- greater -----" << endl;
  int x;
  cin >> x;
  int pp = k.greater(x);
  cout << pp;
  return 0;
}
