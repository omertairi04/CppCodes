#include <iostream>

struct Date {
  int year, month, day;

  int compare(Date date) {
    if (year > date.year)
      return 1;
    else if (year < date.year)
      return -1;
    else {
      if (month > date.month)
        return 1;
      if (month < date.month)
        return -1;
      else {
        if (day > date.day)
          return 1;
        if (day < date.day)
          return -1;
        else
          return 0;
      }
    }
  }

  int daysDifference(Date date) {
    int days = day - date.day;
    days += (month - date.month) * 30;
    days += (year - date.year) * 365;
    return days;
  }
};
void read(Date &date) { std::cin >> date.day >> date.month >> date.year; }

void print(Date &date) {
  std::cout << date.day << "." << date.month << "." << date.year << "\n";
}
int main() {
  Date d1, d2;
  read(d1);
  read(d2);

  int result = d1.compare(d2);
  if (result == 0)
    std::cout << "Dates are equal\n";
  else if (result > 0) {
    std::cout << "The difference in days is: " << d1.daysDifference(d2)
              << " days.\n";
  } else if (result > 0) {
    std::cout << "The difference in days is: " << d2.daysDifference(d1)
              << " days.\n";
  }
}