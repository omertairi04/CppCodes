#include <iostream>
using namespace std;
int main() {
  int day_tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
  int i, leap, day, month, year;
  cout << "Enter a date ";
  cin >> day >> month >> year;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; i++)
    day += day_tab[leap][i];
  cout << "The entered date is the " << day << " day in the year " << endl;
  return 0;
}