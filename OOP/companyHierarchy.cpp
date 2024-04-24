#include <iostream>

class College {

public:
};

class Human {
protected:
  std::string name;
  std::string surName;
  int age;

public:
  Human(std::string name, std::string surName, int age)
      : name(name), surName(surName), age(age) {}

  void setFirstName(std::string name) { this->name = name; };
  void setLastName(std::string surName) { this->surName = surName; };
  void setAge(int age) { this->age = age; };

  void changeName(std::string newName) { name = newName; }

  void showInfo() { std::cout << name << " " << surName << " " << age << "\n"; }
};

int main() {
  Human h("Omer", "Tairi", 19);
  h.showInfo();
  h.changeName("Imran");
  h.showInfo();
}
