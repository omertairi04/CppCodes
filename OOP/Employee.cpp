/*
Write a class that will represent an employee with following attributes:

    name

    salary

    working position (employee, manager or owner).

Write a main function where from SI you will read data for N employees, and then
print a list of employees sorted in descending order by the salary.
*/

#include <cstring>
#include <iostream>
using namespace std;
enum position { employee, manager, owner };
class Employee {
  char name[100];
  int salary;
  position pos;

public:
  Employee() {}
  Employee(char *_name, int _salary, position _position) {
    strcpy(name, _name);
    salary = _salary;
    pos = _position;
  }

  void setName(char *newName) { strcpy(name, newName); }
  char *getName() { return name; }

  void setSalary(int newSalary) { salary = newSalary; }
  int getSalary() { return salary; }

  void setPosition(position pos) { this->pos = pos; }
  position getPosition() { return pos; }

  void printInfo() {
    cout << "Name: " << getName() << "\n";
    cout << "Salary: " << getSalary() << "\n";
    switch (pos) {
    case (0): {
      cout << "Position: Employee \n";
      break;
    }
    case (1): {
      cout << "Position: Manager \n";
      break;
    }
    case (2): {
      cout << "Position: Owner \n";
      break;
    }
    }
  }
};

int main() {
  Employee e;
  float salary;
  char name[100];
  int po;

  cin >> name;
  cin >> salary;
  cin >> po;

  e.setName(name);
  e.setSalary(salary);
  e.setPosition((position)po);

  e.printInfo();
}
