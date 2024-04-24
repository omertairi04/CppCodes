/*
Write a program that reads data about countries from standard input and prints
the name and surname of the president of the country whose capital has the most
inhabitants. Data for a country includes:

    Name
    President
    Capital
    Number of inhabitants.

Data for a city:

    Name
    Number of inhabitants.

Data for the president:

    Name
    Surname
    Political party.

*/

#include <iostream>

struct City {
  char name[100];
  int numOfInhabitants;
};

struct President {
  char name[100];
  char surName[100];
  char politicalParty[100];
};

struct Country {
  char name[100];
  President president;
  City capital;
  int numOfInhabitants;

  void print() {
    std::cout << name << "\t" << president.name << "\t" << president.surName
              << "\t" << president.politicalParty << "\t";
    std::cout << capital.name << "\t";
    std::cout << capital.numOfInhabitants << "\t";
    std::cout << numOfInhabitants << "\n";
  }
};

void print(Country &c) {
  std::cout << c.name << "\t" << c.president.name << "\t";
  std::cout << c.capital.name << "\t";
  std::cout << c.capital.numOfInhabitants << "\t";
  std::cout << c.numOfInhabitants << "\t";
}

void read(int n, Country c[]) {
  for (int i = 0; i < n; i++) {
    std::cin.ignore();
    std::cin.getline(c[i].name, 100);
    std::cin.getline(c[i].president.name, 100);
    std::cin.getline(c[i].president.surName, 100);
    std::cin.getline(c[i].president.politicalParty, 100);
    std::cin.getline(c[i].capital.name, 100);
    std::cin >> c[i].capital.numOfInhabitants;
    std::cin >> c[i].numOfInhabitants;
  }
}

std::string maxCapitalPopulation(int n, Country c[]) {
  Country max = c[0];
  for (int i = 1; i < n; ++i) {
    if (c[i].capital.numOfInhabitants > max.capital.numOfInhabitants) {
      max = c[i];
    }
  }

  return max.president.name;
}

int main() {
  Country countries[100];
  int n;
  std::cin >> n;
  read(n, countries);

  for (int i = 0; i < n; i++) {
    countries[i].print();
  }

  std::cout << maxCapitalPopulation(n, countries);
}

/*

3
USA
Joe
Biden
Democratic Party
Washington DC
705749
328239523
Canada
Justin
Trudeau
Liberal Party
Ottawa
934243
38005238
UK
Boris
Johnson
Conservative Party
London
8908081
67886011

*/