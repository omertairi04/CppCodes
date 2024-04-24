#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
class Student {
private:
  char *ime;
  float prosek;
  int godina;

public:
  Student(const char *ii = "", float pp = 0, int gg = 0) {
    ime = new char[strlen(ii) + 1];
    strcpy(ime, ii);
    prosek = pp;
    godina = gg;
  }
  Student(const Student &u) {
    ime = new char[strlen(u.ime)];
    strcpy(ime, u.ime);
    prosek = u.prosek;
    godina = u.godina;
  }
  ~Student() { delete[] ime; }

  Student &operator=(const Student &u) {
    if (this != &u) {
      delete[] ime;
      ime = new char[strlen(u.ime)];
      strcpy(ime, u.ime);
      prosek = u.prosek;
      godina = u.godina;
    }
    return *this;
  }
  Student &operator++() { // prefiksen operator
    godina++;
    return *this;
  }
  Student operator++(int) { // postfiksen operator
    Student u(*this);
    godina++;
    return u;
  }
  float getProsek() { return prosek; }
  // globalna funkcija za preoptovaruvanje na operatorot <<
  // ovaa funkcija e prijatelska na klasata Student
  friend ostream &operator<<(ostream &o, const Student &u) {
    return o << "Ime:" << u.ime << ", godina:" << u.godina
             << ",prosek:" << u.prosek << endl;
  }
  friend bool operator>(const Student &u1, const Student &u2);
};

// globalna funkcija za preoptovaruvanje na operatorot >
bool operator>(const Student &u1, const Student &u2) {
  return (u1.prosek > u2.prosek);
}

class Class {
private:
  Student *spisok;
  int vkupno;

public:
  Class(Student *s = 0, int v = 0) {
    vkupno = v;
    spisok = new Student[vkupno];
    for (int i = 0; i < vkupno; i++)
      spisok[i] = s[i];
  }

  Class(const Class &p) {
    this->vkupno = p.vkupno;
    this->spisok = new Student[vkupno];
    for (int i = 0; i < vkupno; i++)
      spisok[i] = p.spisok[i];
  }

  ~Class() { delete[] spisok; }
  Class &operator+=(Student u) {
    Student *tmp = new Student[vkupno + 1];
    for (int i = 0; i < vkupno; i++)
      tmp[i] = spisok[i];
    tmp[vkupno++] = u;
    delete[] spisok;
    spisok = tmp;
    return *this;
  }

  Class &operator++() {
    for (int i = 0; i < vkupno; i++)
      spisok[i]++;
    return *this;
  }
  Class operator++(int) {
    Class p(*this);
    for (int i = 0; i < vkupno; i++)
      spisok[i]++;
    return p;
  }

  friend ostream &operator<<(ostream &o, const Class &p) {
    for (int i = 0; i < p.vkupno; i++)
      o << p.spisok[i];
    return o;
  }

  void nagradi() {
    for (int i = 0; i < vkupno; i++)
      if (spisok[i].getProsek() == 10.0)
        cout << spisok[i];
  }

  void najvisokProsek() {
    Student tmpU = spisok[0];
    for (int i = 0; i < vkupno; i++)
      if (spisok[i] > tmpU)
        tmpU = spisok[i];
    cout << "Highest avarage in the Class:" << tmpU.getProsek() << endl;
  }
};

int main() {
  Student u1("Martina Martinovska", 9.5, 3);
  Student u2("Darko Darkoski", 7.3, 2);
  Student u3("Angela Angelovska", 10, 3);

  Class p;
  p += u1;
  p += u2;
  p += u3;

  cout << p;
  cout << "Nagradeni:" << endl;
  p.nagradi();
  cout << endl;
  p.najvisokProsek();
  cout << endl;

  u2++;
  cout << p;
  cout << endl;
  p++;
  cout << p;

  return 0;
}