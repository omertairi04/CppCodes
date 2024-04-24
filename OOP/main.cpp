#include <iostream>
#include <string>

// per me bo override ni metod te parent class at'her ja shtojm para datatype
// virtual, dhe te chill class ja shtojm nmes functionName() override {}

class Person {
  // private cannot be accessed outside this class
protected:
  std::string first;
  std::string last;

public:
  // constructor
  Person(std::string first, std::string last) : first(first), last(last) {}

  Person() = default;

  // or

  // Person(std::string first, std::string last) {
  //   this->first = first;
  //   this->last = last;
  // }

  void setFirstName(std::string firstName) { first = firstName; }

  void setLasttName(std::string last) { this->last = last; }

  std::string getName() { return first; }

  void printFullName() { std::cout << first << " " << last << "\n"; }

  virtual void printInfo() {
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Last Name: " << last << "\n";
  }
};

class Employee : public Person {
  std::string department;

public:
  Employee(std::string firstName = "", std::string lastName = "",
           std::string department = "")
      : Person(firstName, lastName), department(department) {}

  // Corrected function name and return type
  void setDepartment(std::string department) { this->department = department; }

  // Getter function to retrieve the department
  std::string getDepartment() const { return department; }

  void printInfo() override {
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Last Name: " << last << "\n";
    std::cout << "Department: " << department << "\n";
  }

  void changeName(std::string &newName) { first = newName; }

  ~Employee(){};
};

int main() {
  // Person p("Omer", "Tairi"), p2("John", "Doe");
  // p.setFirstName("Omer");
  // p.setLasttName("Tairi");
  // p.printFullName();
  // std::cout << p.getName() << "\n";

  // p2.setFirstName("John");
  // p2.setLasttName("Doe");
  // p2.printFullName();

  // Employee e("Omer", "Tairi", "Sales");
  // std::string newName = "New";
  // e.changeName(newName);
  // e.printInfo();
}