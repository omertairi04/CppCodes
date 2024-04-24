/*
Create an Engine structure that will store horsepower (int) and torque (int)
data.

Then, create a structure Car in which the data of the manufacturer's name (char
array), which year the car was manufactured (int) and which engine (Engine) that
uses it/ will be stored.

At the beginning, a number N is entered that indicates how many cars will be
read from the input.

Then, make the function:

void cars to print (...)

which will take as argument the two cars that have the lowest horsepower, and of
those two, it will print the car that has the torque printed.

For example:
Input 	Result

3       Manufacturer: Opel;Horsepower: 577;Torque: 516
Opel
1999
577
516
Audi
2000
591
590
Citroen
2020
220
321
*/

#include <iostream>

struct Engine {
  int horsePower;
  int torque;

  void read() { std::cin >> horsePower >> torque; }

  void printEngineStats() { std::cout << horsePower << " " << torque << "\n"; }
};

struct Car {
  char manufacturer[100];
  int year;
  Engine engine;

  void read() {
    std::cin.getline(manufacturer, 100);
    std::cin >> year;
    engine.read();
  }

  void printCarStats() {
    std::cout << manufacturer << " " << year << " ";
    engine.printEngineStats();
  }
};

int main() {
  int n;
  std::cin >> n;
  Car car[n];

  for (int i = 0; i < n; i++) {
    car[i].read();
  }

  for (int i = 0; i < n; i++) {
    car[i].printCarStats();
  }
}
